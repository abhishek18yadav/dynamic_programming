#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    vector<int>dp;
    dp.resize(n+4,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}