#include<bits/stdc++.h>
using namespace std;


vector<int>dp;
int f(vector<int>&arr,int x){
    dp[0]=1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<arr.size(); j++){
            if(i<arr[j])continue;
            dp[i]=dp[i]+dp[i-arr[j]];
        }
    }
    return dp[x];
}
int main(){
    int x;
    cin>>x;
    vector<int>arr{2,3,5};
    dp.resize(x+1,0);
    cout<<f(arr,x);
}