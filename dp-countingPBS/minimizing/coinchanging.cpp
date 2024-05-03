#include<bits/stdc++.h>
using namespace std;
vector<int>c;
    vector<int>dp;
    int f(int amount ){
        int ans = INT_MAX;
        if (amount<0)return INT_MAX;
        if(amount==0)return 0;
        if(dp[amount]!= -1)return dp[amount];
        for(int i=0; i<c.size(); i++){
            if(amount>= c[i]){
            ans = min(ans , f(amount-c[i]));
            }
        }
        if(ans== INT_MAX)return dp[amount]= INT_MAX;
        return dp[amount]=1+ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        c=coins;
        dp.resize(10005,-1);
        int res= f(amount);
        return (res == INT_MAX)?-1 : res;
    }
int main(){
    // https://leetcode.com/problems/coin-change/ 
    return 0;
} // min maxi pbs