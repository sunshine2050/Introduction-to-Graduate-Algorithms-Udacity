#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long long_trip(vector<int> locations,vector<int> profit,int k){
  int n = (int) locations.size();
  if(!n) return 0;
  long long P[n];
  P[0] = profit[0];
  for(int i=1;i<n;i++){
    P[i] = 0;
    for(int j=0;j<i;j++){
      if(locations[i] - locations[j] >=k && P[i]<P[j] + profit[i]){
        P[i] = P[j] + profit[i];
        
      }
    }
    
  }
  long long max_profit=0;
  for(int i=0;i<n;i++) max_profit = max(max_profit,P[i]);
  return max_profit;

}
int main() {
  vector<int> vect{ 0, 1, 3, 9, 10};
  vector<int> prof{10,5,1000,10,15};
  long long res = long_trip(vect,prof,3);
  cout<<res<<endl;
}