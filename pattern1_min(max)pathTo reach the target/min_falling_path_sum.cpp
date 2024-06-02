#include<bits/stdc++.h>
using namespace std;


    vector<vector<int>> m;
    vector<vector<int>>dp;
    int f(int i, int j){
        if(i<0 or i>= m.size() or j<0 or j>=m[0].size())return INT_MAX;
        if(i==m.size()-1)return m[i][j];
        if(dp[i][j]!= -1)return dp[i][j];
        int ans = m[i][j]+min(f(i+1,j-1),min(f(i+1,j),f(i+1,j+1)));
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int b =1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]!=0)b=0;
            }
        }
        if(b==1)return 0;
        dp.resize(105,vector<int>(105,-1));
        m=matrix;
        int sum=INT_MAX;
        for(int i=0; i< m[0].size(); i++){
            sum = min(sum,f(0,i));
        }
        return sum;
    }

int main(){
    vector<vector<int>> matrix{{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
    return 0;

}