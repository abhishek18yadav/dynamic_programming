#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
//fibo no at nth pos
int fibo(int n){
    if(n==0 or n==1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo(n-1)+ fibo(n-2);
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+4,-1);
    cout<<fibo(n);
    return 0;
}