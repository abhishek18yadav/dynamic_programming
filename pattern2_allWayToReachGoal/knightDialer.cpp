#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
    vector<vector<int>>v{
                        {4,6},
                        {6,8},
                        {7,9},
                        {4,8},
                        {0,3,9},
                        {},
                        {0,1,7},
                        {2,6},
                        {1,3},
                        {2,4},
    };
    vector<vector<int>>dp;
    int f(int i , int n){
        if(n==0)return 1;
        if(dp[i][n]!= -1)return dp[i][n];
        int ans=0;
        for(auto ele : v[i]){
           ans = (ans%mod + f(ele, n-1)%mod)%mod;
        }
        return dp[i][n]= ans%mod;
    }
    int knightDialer(int n) {
        int ans = 0;
        dp.resize(5003, vector<int>(5002,-1));
        for(int i=0; i<=9; i++){
           ans= (ans%mod + f(i,n-1)%mod)%mod;
        }
        return ans%mod;
    }
int main(){
    cout<<knightDialer(3131);
    return 0;
}