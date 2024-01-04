/**
 * ques-> lexographical printing till no n
*/
#include<bits/stdc++.h>
using namespace std;

void f(int idx , int n){
    if(idx>n)return ;
    if(idx>0 and idx<= n){
        cout<<idx<<" ";
    }
    for(int j=0; j<=9; j++){
        f(10*idx+j,n);
    }
}
int main(){
    int n=17;
    for(int i=1; i<=9 ;i++){
        f(i,n);
    }
    return 0;
}