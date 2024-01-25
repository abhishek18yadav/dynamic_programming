#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-increasing-subsequence/description/

vector<int >dp;
int f( int idx ,vector<int>&nums){
    int maxseq=INT_MIN;
    if(idx==0)return 1;
    if(dp[idx]!=-1)return dp[idx];
    for(int j=0; j<idx; j++){
        if(nums[j]<nums[idx]){
         maxseq= max(maxseq,f(j,nums));
        }
    }
    if(maxseq==INT_MIN) return dp[idx]=1;
    else return dp[idx]=1+maxseq;
}
int lengthOfLIS(vector<int>& nums) {
    dp.resize(nums.size()+3 , -1);
    int mx = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        mx = max(mx , f(i,nums));
    }
    return mx;
}

int main(){
    vector<int>nums{10,9,2,5,3,7,101,18};
    
    cout<<lengthOfLIS(nums);
    return 0;
}