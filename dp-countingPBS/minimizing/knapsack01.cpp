#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
vector<int>p;
vector<int>wt;

int f(int idx ,int n , int w){
    if(idx == n)return 0;
    if(w<=0)return 0;
    int maxpr= INT_MIN;
    maxpr = f(idx+1,n,w);
    if(w>=wt[idx]){
        maxpr = max(maxpr ,p[idx]+ f(idx+1, n, w-wt[idx]));
    }
    return maxpr;
}
int knapsack(vector<int>&profit, vector<int>&weight , int n , int w){
    p=profit;
    wt =weight;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans , f(i,n,w));
    }
    return ans;
} 


int main(){
    vector<int>profit{1,2,3};
    vector<int>weight{4,5,1};
    int n=3;
    int w=4;
    cout<<knapsack(profit,weight,n,w);
    return 0;
}
// min max problem