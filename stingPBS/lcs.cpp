#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
    int f(string text1, string text2, int i, int j){
        if(i == -1 || j == -1) {
                // if any one opf the string has been exhausted return 0
                return 0;
            }
            
            if(dp[i][j] != -1) return dp[i][j];
            
            if(text1[i] == text2[j]) {
                return dp[i][j] = 1 + f(text1, text2, i-1, j-1);
            } else {
                return dp[i][j] = max(f(text1, text2, i-1, j), f(text1, text2, i, j-1));
            }
    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0; i<1005; i++){
            for(int j=0; j<1005; j++){
                dp[i][j]=-1;
            }
        }
        return f(text1,text2,text1.size()-1,text2.size()-1);
    }
int main(){
    // https://leetcode.com/problems/longest-common-subsequence/
    cout<<longestCommonSubsequence("abcde","ace");
    return 0;
}