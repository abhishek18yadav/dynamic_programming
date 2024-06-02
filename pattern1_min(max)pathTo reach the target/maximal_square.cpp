#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>>dp;
    vector<vector<char>> m;
    int f(int i,int j ,int maxans){
        if(i>=m.size() or j>= m[0].size())return 0;
        

        if(dp[i][j] != -1)return dp[i][j];
        int right = f(i,j+1,maxans);
        int down = f(i+1,j,maxans);
        int diag = f(i+1,j+1,maxans);
        
         if (m[i][j]=='1'){
            int ans = 1+ min({right , down , diag});
            maxans= max(maxans , ans);
            return dp[i][j]=  ans;
        }
        else if(m[i][j]=='0') {
            return 0;
        }
        return dp[i][j]=  maxans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix;
        dp.resize(303,vector<int>(303,-1));
        int ans = INT_MIN;
        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                ans = max(ans,f(i,j,INT_MIN));
            }

        }
        return ans*ans;
    }
int main(){


    vector<vector<char>>matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalSquare(matrix);
    return 0;
}