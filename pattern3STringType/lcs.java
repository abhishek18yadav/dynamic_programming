package dynamic_programming.stingPBS;
class Solution {
    String s1= new String();
    String s2= new String();
    int dp[][] = new int [1005][1005];

    int f(int i, int j){

        if(i== -1 ||  j==-1) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j)){
            return 1+f(i-1,j-1);
        }
         return dp[i][j]=  Math.max(f(i,j-1) , f(i-1,j));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        s1=text1;
        s2= text2;
        for(int i=0; i<1005; i++){
            for(int j=0; j<1005; j++){
                dp[i][j]=-1;
            }
        }
        return f(text1.length()-1, text2.length()-1);
    }
}