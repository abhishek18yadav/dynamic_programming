#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int f(int no){
    int sum=0;
    if(no==0)return 1;
    if(dp[no]!=-1)return dp[no];
    for(int i=1; i<=6; i++){
        if(no-i <0)break;
        sum+=f(no-i);
    }
    return dp[no]=sum % 1000000007;
}
int main(){
    int n;
    cin>>n;
    dp.resize(10,-1);
    cout<<f(n);
    return 0;
}