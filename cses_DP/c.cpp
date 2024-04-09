#include<bits/stdc++.h>
using namespace std;


void f(vector<int>&arr,int tar,vector<int>&v){
    if(tar<0)return ;
    if(tar==0){
        cout<< v.size()<<" ";
        return ;
    }
    for(int i=0; i<arr.size(); i++){
        v.push_back(arr[i]);
        f(arr,tar-arr[i],v);
    }
}

int main(){
    vector<int>arr{2,3,5};
    int tar=9;
    vector<int>v(10,0);
    f(arr,tar,v);
    return 0;
}