#include<bits/stdc++.h>
using namespace std;

vector<int>p;
    int dp[100005][2][2];
    int f(int i , int k,int on){
        // on check whether we have some stock or not
        if(i==p.size())return 0;
        int ans = INT_MIN;

        if(dp[i][k][on] != -1)return dp[i][k][on];
        ans = max(ans , f(i+1,k,on));
        if(on==0 and k>0){
            ans = max(ans, -p[i]+f(i+1,k,1));
        }
        if(on){
            ans= max(ans,p[i]+f(i+1,k-1,0));
        }
        return dp[i][k][on]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        p=prices;
        for(int i=0; i<100005; i++){
            for(int j=0; j<2; j++){
                for(int z=0; z<2; z++){
                    dp[i][j][z]=-1;
                }
            }
        }
        return f(0,k,0);
    }
int main(){
    vector<int>prices{3,5,0,0,3,1,4};
    int k=2;
    cout<<maxProfit(k,prices);
    return 0;
}