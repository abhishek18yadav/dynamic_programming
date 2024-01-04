/**
 * ques->  Given a number N. The task is to reduce the given number N to 1 in the minimum number of steps. You can perform any one of the below operations in each step.

          Operation 1: If the number is divisible by 2 then you can divide the number by 2.
           Operation 2: If the number is divisible by 3  then you can divide the number by 3.
        Operation 3: n-> n-1;
        take out min steps to convert it
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int f(int n){
    if(n==1)return 0;
    if(n==2 or n==3)return dp[n]=1;
    return dp[n]=1+min({(n%3==0)?f(n/3):INT_MAX, (n%2==0)?f(n/2):INT_MAX , f(n-1)});
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+3,-1);
    cout<<f(n);
    return 0;
}