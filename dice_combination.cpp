#include<bits/stdc++.h>
using namespace std;
// void file_i_o(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }
int no;
vector<int>dp;
int f(int no){
    dp[0]=dp[1]=1;
    for(int i=2; i<=no;i++){
        for(int j=1; j<=6; j++){
            if(j>i)continue;
            dp[i]= dp[i]+dp[i-j];
        }
    }
    return dp[no];
}
int main(){
    cin>>no;
    dp.resize(no+1,0);
   cout<<f(no);
    return 0;
}