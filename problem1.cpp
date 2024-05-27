#include<bits/stdc++.h>
using namespace std;
/**
 * As a seasoned robber planning to target houses along a street, you are provided with a list of N houses. Each house contains a certain amount of money, represented by the array 'house,' where positive values indicate more money relative to danger and negative values indicate more danger compared to money.

Your task is to determine the minimum number of consecutive houses you can rob such that the total sum of money is at least k. If there is no feasible plan to achieve a sum of at least k, return -1 as it is not worth the risk.

Input Format

The First line of input contains an integer n. 
The following n line of input contains an integer.
The following line contains an integer k.
Constraints

1 <= house.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109
Output Format

It will be an integer which represent the minimum number of consecutive houses rob such that the total sum of money is at least k .
Sample test case

Input

3
2
-1
2
3
Output

3
Explanation :

As we given n =3 , house = [2,-1,2] , k=3

House '0' has total money is 2.

Houses '0' and '1' together have total money of 1.

Houses '0', '1', and '2' together have a total money of 3.

Houses '1' and '2' have a total money of 1.

House '2' has total money of 2.

So the answer is 3; a minimum of 3 consecutive houses are required.

*/
vector<int>arr;
vector<int>res;
bool cmp(int a,int b){
    return a>b;
}
int f(int idx, int count, int val, int k){
    if(val>=k){
        res.push_back(count);
    }
    if(idx>= arr.size())return val;
    int ans = INT_MIN;
    
    ans = max(ans , f(idx+1, 0,0, k));
    count+=1;
    ans= max( ans , f(idx+1 , count , val+arr[idx] ,k));
    return ans;
}
int main(){
    vector<int>v{1,2,-3,2,2};
    res.resize(arr.size(),-1);
    for(int i=0; i<res.size(); i++){
        res[i]=-1;
    }
    arr=v;
    int k=4;
    int h=f(0,0,0, 4);
    sort(res.begin(),res.end(),cmp);
    cout<<res[0];
    return 0;
}