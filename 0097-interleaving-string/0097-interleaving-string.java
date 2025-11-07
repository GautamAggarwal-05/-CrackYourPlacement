class Solution {
    Boolean [][] dp = new Boolean[101][101];
    boolean solve(int i,int j,int k,String s1,String s2, String s3){
        if(k==s3.length() && i==s1.length() && j==s2.length()){
            return true;
        }
        if(k>=s3.length())
            return false;
        if(dp[i][j]!=null)
            return dp[i][j]; 
        boolean result = false ;
        if(i<s1.length() && k<s3.length() && s1.charAt(i) == s3.charAt(k))
            result = solve(i+1,j,k+1,s1,s2,s3);
        if(result == true){
            return dp[i][j] = result;
        }
        if(j<s2.length() && k<s3.length() && s2.charAt(j) == s3.charAt(k))
            result = solve(i,j+1,k+1,s1,s2,s3);
        
        return dp[i][j] = result;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) 
            return false;
        return solve(0,0,0,s1,s2,s3);
    }
}