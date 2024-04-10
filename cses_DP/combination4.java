class Solution {
    int []n;
    int []dp;
    public int f(int target){
        if(target==0)return 1;
        if(target < 0)return 0;
        int ans= 0;
        if(dp[target]!= -1)return dp[target];
        for(int i=0; i<n.length; i++){
            if(target>=n[i]){
                ans +=f(target-n[i]);
            }
        }
        return dp[target]=ans;
    }
    public int combinationSum4(int[] nums, int target) {
        n= nums;
        dp = new int[1003];
        Arrays.fill(dp,-1);
        int res = f(target);
        return res;
    }
}