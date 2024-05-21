#include<bits/stdc++.h>
using namespace std;


    vector<int>n;
    // int dp[2503][2503];
    vector<vector<int>>dp;
    int f(int currentidx , int previdx){
        if(currentidx ==n.size())return 0;
        int ans = INT_MIN;
        if(previdx == -1)return 1+f(currentidx +1 , currentidx);
        if(dp[currentidx][previdx] != -1)return dp[currentidx][previdx];
         ans =  max(ans ,f(currentidx+1 , previdx));
        if(n[previdx]<n[currentidx])return dp[currentidx][previdx] =ans = max(ans ,1+f(currentidx +1 , currentidx));
        return dp[currentidx][previdx]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        // for(int i=0; i<2503; i++){
        //     for(int j=0; j<2503 ; j++){
        //         dp[i][j]=-1;
        //     }
        // }
        dp.resize(2503,vector<int>(2503,-1));
        n= nums;
        int ans = INT_MIN;
        for(int i=0; i<n.size(); i++){
            ans = max(ans , f(i,-1));
        }
        return ans;
    }
int main(){
    vector<int>nums{10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums);
    return 0;
}
// https://leetcode.com/problems/longest-increasing-subsequence/