#include<bits/stdc++.h>
using namespace std;


    vector<int>p;
   int f(int i, int k, int on){
         if(i== p.size()) return 0;


        int ans = INT_MIN;
         // ignore
         ans = max(ans , f(i+1,k,on));
//         buy
         if(on==0 and k>0){
            
            ans= max(ans, -p[i]+f(i+1,k,1));
            
         }
         // sell
         if(on==1){
           
            ans = max(ans, p[i]+ f(i+1,k-1,0));
         }
         return ans;
   }
    int maxProfit(vector<int>& prices) {
        p=prices;
        return f(0,2,0);
    }
    
    int main(){
        vector<int>prices{3,5,0,0,3,1,4};
        cout<<maxProfit(prices);
        return 0;
    }// min max pbs