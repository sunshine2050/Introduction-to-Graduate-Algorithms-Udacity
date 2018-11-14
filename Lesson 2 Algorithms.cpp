//============================================================================
// Name        : Algorithms.cpp
// Author      : Ahmad Samy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;



/*  *********************************************** Fibonachi Numbers ************************************* */

//recursive exponential running time as fib numbers compute many times
long long fibRecursive(int n){
	if(n==1) return 1;
	if(n==0) return 0;
	return fibRecursive(n-1) + fibRecursive(n-2);
}

//getting over the problem of computing the same value more than ones by saving the previous values

/* steps:
   -----
1: define subproblem in words
   F[i] = ith fibonachi number

2: state a recursive relation (express the solution to the ith subproblem in term of smaller subproblems)
   express F[i] in terms of F[1],..,F[i-1]
   F[i] = F[i-1] + F[i-2]


*/
long long fibDP(int n){
	int arr[n+1];
	arr[0] = 0; arr[1] = 1;
	for(int i=2;i<=n;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

/* ****************************************************** End of Fibonachi ******************************************* */



/* ****************************************************** Longest Increasing Subsequence ***************************** */

/* steps:
   -----
1: define subproblem in words
	Let L[i] = length of LIS on a1,a2,....,ai which includes ai

2: state a recursive relation (express the solution to the ith subproblem in term of smaller subproblems)
	express L[i] in terms of L[1],L[2],...,L[i-1]
	L[i] = 1 + max(j){L(j), aj<ai}

 */

int LIS(int a[],size_t n){
	int L[n];
	L[0] = 1;
	int lis = 1;
	for(size_t i=1;i<n;i++){
		L[i] = 1;
		for(size_t j=0;j<i;j++){
			if(a[j] < a[i]) L[i] = max(L[j] + 1,L[i]);
		}
		lis = max(L[i],lis);
	}


	return lis;
}
/* ****************************************************** End of Longest Increasing Subsequence ***************************** */


/* ***************************************************** Longest Common Subsequence ************************************** */
int LCM(string s1,string s2) {
	int n = s1.length();
	int m = s2.length();
	int L[n+1][m+1];

	for(int i=0;i<n;i++) L[i][0] = 0;
	for(int j=0;j<m;j++) L[0][j] = 0;


	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s1[i] == s2[j]) L[i][j] =1 + L[i-1][j-1];
			else L[i][j] = max(L[i-1][j],L[i][j-1]);
		}
	}
	return L[n][m];
}


int main() {
	/* ********************************** Testing Fibonachi ********************** */
	int test = 30;

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	long long res1 = fibRecursive(test);
	chrono::steady_clock::time_point end= chrono::steady_clock::now();

	cout << "Time taken for Recursive Algorithm "<< chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<" Result = "<<res1<<"\n\n";

	begin = chrono::steady_clock::now();
	long long res2 = fibDP(test);
	end = chrono::steady_clock::now();


	cout << "Time taken for DP Algorithm "<< chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<" Result = "<<res2<<"\n\n";

	/* ********************************** End of Testing Fibonachi ********************** */


	/* ********************************** Testing LIS *********************************** */

	int arr[] = {5, 7, 4, -3, 9, 1, 10, 4, 5, 8, 9, 3};
	begin = chrono::steady_clock::now();
	res1 = LIS(arr,12);
	end= chrono::steady_clock::now();

	cout << "Time taken for LIS Algorithm "<< chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<" Result = "<<res1<<"\n\n";


	/* ********************************** End of Testing LIS *********************************** */


	/* ********************************** Testing LCM ****************************************** */

	string s1 = "BCDBCDA";
	string s2 = "ABECBAB";

	begin = chrono::steady_clock::now();
	res1 = LCM(s1,s2);
	end= chrono::steady_clock::now();
	cout << "Time taken for LCM Algorithm "<< chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<" Result = "<<res1<<"\n\n";

	/* ********************************** End of Testing LCM ****************************************** */
	return 0;
}
