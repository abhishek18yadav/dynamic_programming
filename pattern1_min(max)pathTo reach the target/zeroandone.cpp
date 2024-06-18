#include<bits/stdc++.h>
using namespace std;


    #define pp pair<int,int>
    vector<string>s;
    int dp[605][105][105];
    pp f2(string str){
        pp p1;
        int one=0,zero =0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='1')one++;
            else zero++;
        }
        p1.first = zero;
        p1.second= one;
        return p1;
    }
    int f(int idx, int m , int n){
        if(idx>= s.size() or m<0 or n<0)return 0;
        if(m==0 and n==0)return 0;
        if(dp[idx][m][n] != -1)return dp[idx][m][n];
        int ans =INT_MIN;
        ans = f(idx+1,m,n);
        pp count = f2(s[idx]);
        if(m-count.first >=0  and n-count.second >=0){
            ans=max(ans, 1+f(idx+1,m-count.first, n-count.second));
        }
        return dp[idx][m][n]= ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        s=strs;
        for(int i=0; i<605; i++){
            for(int j=0; j<105; j++){
                for(int k=0; k<105; k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<strs.size(); i++){
            ans = max(ans ,f(0,m,n) );
        }
        return ans;
    }

int main(){
    vector<string> strs {"10","0001","111001","1","0"};
    int m =5;
    int n=3;
    cout<<findMaxForm(strs , m ,n);
    return 0;
}