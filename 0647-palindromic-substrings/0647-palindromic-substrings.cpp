class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        vector<string>res;
        int count=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            count++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                count++;
            }
        }

        for(int diff=2;diff<n;diff++){
            for(int i=0;i<n-diff;i++){
                int j=i+diff;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    count++;
                }
            }
        }
        return count;
    }
};