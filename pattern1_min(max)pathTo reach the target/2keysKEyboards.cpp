#include<bits/stdc++.h>
using namespace std;


//sol refer https://leetcode.com/problems/2-keys-keyboard/solutions/3688193/efficient-c-dp-solution/?envType=problem-list-v2&envId=55ac4kuc//

int f(int n, int presch,  int copych){

        if(presch==n)return 0;
        

        int ans = 2000;

        
        if((presch + presch) <=n ){
            
            int cp =  2+ f(n, presch + presch , presch);
            // copy and pasting both 
            ans= min(ans,cp);
        }
        if((presch + copych) <=n ){
            
            int p =  1+ f(n, presch + copych , copych);
            ans= min(ans,p);
        }
        
        return ans;
    }
    
    int minSteps(int n) {
        if(n==1)return 0;
        // we are starting with copy-paste operation so,
        // present char = AA and copied char A
        
        return 2+f(n, 2,1);
    }
int main(){
    cout<<minSteps(56);
    return 0;
}