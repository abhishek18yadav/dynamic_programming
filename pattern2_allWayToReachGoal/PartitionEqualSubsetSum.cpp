#include<bits/stdc++.h>
using namespace std;


vector<int>n;
    vector<vector<int>>dp;
    bool f(int idx, int tar){
        if(tar == 0 )return true;
        if(tar < 0)return false;
        if(tar >0 and idx>=n.size())return false;
        if(dp[idx][tar] != -1)return dp[idx][tar];
        bool take = f(idx+1 , tar-n[idx]);
        bool nottake = f(idx+1 , tar);
        return dp[idx][tar]= take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        n= nums;
        bool res=0;
        dp.resize(205, vector<int>(10008, -1));
        if(sum%2 != 0)return false;
        else{
            int tar = sum/2;
            res = f(0,tar);
        }
        return res;
    }

int main(){

    vector<int>nums{1,5,11,5};
    cout<<canPartition(nums);
    return 0;
}
