class Solution {
    public String longestPalindrome(String s) {
        StringBuilder res = new StringBuilder();
        // ArrayList<ArrayList<Boolean>> dp = new ArrayList<>();
        int n = s.length();
        int start=0;
        int end=0;
        boolean [][] dp = new boolean[n][n];
        // for(int i=0;i<n;i++){
        //     ArrayList<Boolean> row = new ArrayList<>(Collections.nCopies(n,false));
        //     dp.add(row); 
        // }

        for(int i=0;i<n;i++){
            dp[i][i]=true;
            start=i;
            end=i;
        }
        for(int i=0;i<n-1;i++){
            if(s.charAt(i)==s.charAt(i+1)){
                dp[i][i+1]=true;
                start=i;
                end=i+1;
            }
        }
        
        for(int diff=2;diff<n;diff++){
            for(int i=0;i<n-diff;i++){
                int j=i+diff;
                if(dp[i+1][j-1] && s.charAt(i)==s.charAt(j)){
                    dp[i][j]=true;
                    start=i;
                    end=j;
                }
            }
        }
    System.out.println(start+" "+end);
    return s.substring(start,end+1);
    }
}