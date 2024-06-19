#include<bits/stdc++.h>
using namespace std;

    int r;
    int c;
    vector<vector<int>>pos{
        {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}
    };
    double dp[105][29][29];
    double f(int k, int i, int j){
        if(i<0 or j<0 or i>=r or j>=c)return 0.0;
        if(k==0)return 1.0;
        if(dp[k][i][j] != -1)return dp[k][i][j];
        double prob = 0.0;
        for(auto ele : pos){
            int x= ele[0];
            int y= ele[1];
            prob += f(k-1 , i+x , j+y);
        }
        return dp[k][i][j]= prob/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        r=n;
        c=n;
        for(int i=0; i<105; i++){
            for(int j=0; j<29; j++){
                for(int z=0; z<29; z++){
                    dp[i][j][z]=-1;
                }
            }
        }
        return f(k,row, column);
    }

int main(){
    int n=3;
    int k =2;
    int row = 0;
    int column = 0;
    cout<<knightProbability(n,k,row,column);
    return 0;
}