#include<bits/stdc++.h>
using namespace std;


    vector<int>e;
    vector<int>dp;
    int f(int idx,int k){
        if(idx >= e.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans = INT_MIN;
        if(idx < e.size()){
             ans = max(ans,e[idx]+f(idx + k,k));
        }
        if(ans==INT_MIN)return INT_MIN;
        return dp[idx] = ans;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        e=energy;
        dp.resize(100005,-1);
        int res = INT_MIN;
        for(int i=0; i<e.size(); i++){
            res = max(res,f(i,k));
        }
        return res;
    }


int main(){
    vector<int>energy{5,2,-10,-5,1};
    int k=3;
    cout<<maximumEnergy(energy,k);
    return 0;
}