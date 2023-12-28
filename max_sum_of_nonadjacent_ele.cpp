#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int f(vector<int>&arr,int idx){
    if(idx==0)return dp[idx]=arr[idx];
    if(idx<0)return 0;
    if(dp[idx]!= -1)return dp[idx];
    int pick = arr[idx]+ f(arr,idx-2);
    int not_p = f(arr,idx-1);
    return  dp[idx]=max(pick,not_p);
}

int main(){
    dp.clear(); 
    vector<int>arr{2,1,4,9};
    dp.resize(arr.size(),-1);
    int k=2;
    int ans=f(arr,arr.size()-1);
    cout<<ans;
    return 0;
}