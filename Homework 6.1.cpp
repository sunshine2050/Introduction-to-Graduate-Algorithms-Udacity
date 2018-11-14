#include <iostream>
#include <vector>

using namespace std;

long long MSCS(vector<int> arr){
  int n = (int) arr.size();
  if(!n) return 0;
  long long sum[n];
  sum[0] = (arr[0]>=0?arr[0]:0);
  for(int i=1;i<n;i++){
    sum[i] = max((long long)arr[i],(long long)arr[i] + sum[i-1]);
  }
  return sum[n-1];

}
int main() {
  vector<int> vect{ 5, 15, -30, 10, -5, 40, 10};
  long long res = MSCS(vect);
  cout<<res<<endl;
}