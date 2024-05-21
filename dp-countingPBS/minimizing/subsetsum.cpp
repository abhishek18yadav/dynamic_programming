#include<bits/stdc++.h>
using namespace std;

vector<int>s;

int f(int sum, int idx){
        int ans = INT_MAX;
    if(sum==0){
        return 0;
    };
    if(sum<0 or idx>= s.size())return INT_MAX;
    // not counting
    ans =min(ans,f(sum, idx+1));
    // taken
    if(sum>= s[idx]){
    ans = min(ans ,f(sum-s[idx], idx+1));        
    }
    if(ans==INT_MAX)return INT_MAX;
    return 1+ans;
}
int subsetsum(vector<int>&sub, int sum){
    s= sub;
    int res = INT_MAX;
    for(int i=0; i<sub.size();i++){
        res = min(res, f(sum,i));
    }
    return (res== INT_MAX)?-1 : res-1;
}
// int f(int sum){
//     if(sum==0 )return 0;
//     if(sum<0)return INT_MAX;
//     int ans = INT_MAX;
//     for(int i=0; i<s.size(); i++){
//         if(sum>= s[i]){
//             ans = min(ans, f(sum-s[i]));
//         }
//     }
//     if(ans==INT_MAX)return INT_MAX;
//     return 1+ans;
// }
// int subsetsum(vector<int>&sub, int sum){
//     s= sub;
//     return f(sum);
// }
  /**
   * note 
   * 
   * comments code is executing correctly but not correct logic
   * 
   * 1st logic is correct but not giving right ans;
  */
int main(){
    vector<int>sub{1,3,34,4,12,5,21};
    int sum=9;
    cout<<subsetsum(sub,sum);
    return 0;
}