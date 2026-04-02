class Solution {
    public int maximumAmount(int[][] coins) {
        Integer dp[][][]=new Integer[coins.length][coins[0].length][3];
        return compute(0,0,coins,2,dp);
    }
    public int compute(int i,int j,int[][] coins,int left,Integer dp[][][]){
        int m=coins.length,n=coins[0].length;
        if(i==m-1&&j==n-1){
            if(coins[i][j]<0&&left>0) return 0;
            return coins[i][j];
        }
        if(i==m||j==n) return (int)-1e7;
        if(dp[i][j][left]!=null) return dp[i][j][left];
        int ans=coins[i][j]+compute(i+1,j,coins,left,dp);
        ans=Math.max(ans,coins[i][j]+compute(i,j+1,coins,left,dp));
        if(left>0&&coins[i][j]<0){
            ans=Math.max(ans,compute(i+1,j,coins,left-1,dp));
            ans=Math.max(ans,compute(i,j+1,coins,left-1,dp));
        }
        return dp[i][j][left]=ans;
    }
}