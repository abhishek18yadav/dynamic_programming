#include<bits/stdc++.h>
using namespace std;


    string s1;
    string s2;
    vector<vector<int>>dp;
    int f(int i, int j){
        if(i>=s1.size() or j>= s2.size())return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])ans+= 1+f(i+1, j+1);
        else{
            ans= max(f(i+1,j), f(i,j+1));
        }
        return dp[i][j]= ans;
    }
    int longestPalindromeSubseq(string s) {
        s1=s;
        string str="";
        dp.resize(1005,vector<int>(1005,-1));
        int i=s1.length()-1;
        while(i>=0){
            str+=s1[i];
            i--;
        }
        s2=str;
        return f(0,0);
    }
int main(){
    string s = "abcbd";
    cout<<longestPalindromeSubseq(s);
    return 0;
}