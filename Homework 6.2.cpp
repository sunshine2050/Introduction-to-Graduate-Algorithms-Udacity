#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long long_trip(vector<int> arr){
  int n = (int) arr.size();
  long long P[n];
  set <int> path;
  P[0] = 0;
  path.insert(n-1);
  for(int i=1;i<n;i++){
    P[i] = 1e18;
    for(int j=0;j<i;j++){
      if(P[j] < P[i]){
        P[i] = min(P[j] + ((200 - (arr[i] - arr[j])) * (200 - (arr[i] - arr[j]))),P[i]);
        
      }
    }
    for(int j=0;j<i;j++){
      if(P[i] == P[j] + ((200 - (arr[i] - arr[j])) * (200 - (arr[i] - arr[j])))){
        path.insert(j);
        break;
        
      }
    }
    
  }
  for(set<int>::iterator it=path.begin();it!=path.end();it++) cout<<*it <<" ";
  cout<<"\n\n";
  return P[n-1];

}
int main() {
  vector<int> vect{ 0, 100, 300, 350, 500};
  long long res = long_trip(vect);
  cout<<res<<endl;
}