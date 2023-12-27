#include<bits/stdc++.h>
using namespace std;
bool check_reptetion(int no){
    vector<int>v;
    int count=0;
    while(no){
        v.push_back(no%10);
        no/=10;
        count++;
    }
    for(int i=0; i<count-1; i++){
        if(v[i]== v[i+1]){
            return false;
        }
    }
    return true;
}
int finding_no(int a ,int b, int count){
    if(a==b+1)return count;
        if(check_reptetion(a)){
           count++;
        }
       return finding_no(a+1,b,count);
}
int main(){
    int strt=123;
    int end=321;
    int ans=finding_no(strt,end, 0);
    cout<<ans;
    return 0;
}