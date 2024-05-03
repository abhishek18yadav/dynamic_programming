#include<bits/stdc++.h>
using namespace std;

vector<int>sq;
vector<int>dp;
    int f(int n){
        if(n==0 or n==1)return n;
        int ans = INT_MAX;
        if(dp[n]!= -1)return dp[n];
        for(int i=0; i<sq.size(); i++){
            if(n>=sq[i]){
                ans = min(ans, f(n-sq[i]));
            }
        }
        if(ans==INT_MAX)return dp[n]= INT_MAX;
        return dp[n]=1+ans;
    }
    int numSquares(int n) {
        sq.resize(100,0);
        dp.resize(10002,-1);
        int j=0;
        for(int i=1; i*i<=10000; i++){
            sq[j]= i*i;
            j++;
        }
        return f(n);
    }
int main(){
    return 0;
}