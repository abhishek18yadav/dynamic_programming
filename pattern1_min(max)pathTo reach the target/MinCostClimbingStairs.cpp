#include<bits/stdc++.h>
using namespace std;

vector<int>c;
    vector<int>dp;
    int f(int idx){
        if(idx==c.size()-1)return 0;
        if(dp[idx+1]!=-1)return dp[idx+1];
        int ans =0;
        if(idx+2 < c.size()){
            ans =  min(c[idx+1]+f(idx+1) , c[idx+2] + f(idx+2));
        }
        return dp[idx+1]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        c= cost;
        dp.resize(1005, -1);
        return f(-1);
    }
int main(){
    vector<int>cost{10,15,20};
    cout<<minCostClimbingStairs(cost);
    return 0;
}