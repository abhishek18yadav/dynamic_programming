#include<bits/stdc++.h>
using namespace std;
 // https://leetcode.com/problems/triangle/
    vector<vector<int>>dp;
    int f(int r, int c,vector<vector<int>>& triangle){
        if(r== triangle.size()-1 )return triangle[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]=triangle[r][c]+min(f(r+1,c,triangle) ,f(r+1,c+1,triangle) );
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(203, vector<int>(204 , -1));
         return f(0,0,triangle);
    }

int main(){
    vector<vector<int>>triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
     cout<<minimumTotal(triangle);
    return 0;
}