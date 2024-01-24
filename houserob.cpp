#include<bits/stdc++.h>
using namespace std;
//top down approach
vector<int>dp;
int f(vector<int>&houses, int idx){
    if(idx>=houses.size())return 0;
    if(idx == houses.size()-1)return houses[houses.size()-1];
    if(idx == houses.size()-2)return dp[idx]=max(houses[houses.size()-2],houses[houses.size()-1]);
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx]=max( houses[idx]+f(houses,idx+2) , 0+f(houses,idx+1));
}
int main(){
    vector<int>houses{1,2,3,1};
    dp.resize(houses.size()+3,-1);
    cout<<f(houses,0);
    return 0;
}