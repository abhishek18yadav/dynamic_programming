/**
 * Q-> there are n stones numbered 1.2.3....N .for each i(1<=i<=N)the height of stone i is hi. 
 * there is a frog who is initially on stone i, he will repeat the following action some no of times io resach stone N
 * if the frog is currently on stone i, jump to one of the following stone , i+1.....i+k,
 * here a cost of (hi- hj)is incurred, where j is stone to land on.
 * find min cost to reach on N
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int f(int i, vector<int>&arr,int k,int ans){
    if(i==arr.size()-1)return 0;
    if(i>=arr.size())return INT_MAX;
    if(dp[i]!= -1)return dp[i];
    for(int j=1; j<=k; j++){
        if(i+j >= arr.size())continue;
        ans =dp[i]= min(ans,abs(arr[i]-arr[i+j])+f(i+j,arr,k,ans));
    }
    return ans;
}
int main(){
    vector<int>arr{1,2,3,4,5};
    dp.resize(arr.size(),-1);
    int k=3;
    cout<<f(0,arr,k,INT_MAX);
    return 0;
}