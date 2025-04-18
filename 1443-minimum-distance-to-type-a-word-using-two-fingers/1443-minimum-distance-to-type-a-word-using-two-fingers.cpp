class Solution {
public:
    unordered_map<int,pair<int,int>>mp;
    int solve(int i,int finger1,int finger2,int n,string& word,vector<vector<vector<int>>> &dp){
        if(i>=n)
            return 0;
        if(dp[i][finger1+1][finger2+1]!=-1){
            return dp[i][finger1+1][finger2+1];
        }
        int firstfinger=0;
        if(finger1==-1){
            firstfinger=solve(i+1,word[i]-'A',finger2,n,word,dp);
        }
        else{
            int prevrow=finger1/6;
            int prevcol=finger1%6;
            int currrow=(word[i]-'A')/6;
            int currcol=(word[i]-'A')%6;
            int dist=(abs(currrow-prevrow)+abs(currcol-prevcol));
            firstfinger=dist+solve(i+1,word[i]-'A',finger2,n,word,dp);
        }

        int secondfinger=0;
        if(finger2==-1){
            secondfinger=solve(i+1,finger1,word[i]-'A',n,word,dp);
        }
        else{
            int prevrow=finger2/6;
            int prevcol=finger2%6;
            int currrow=(word[i]-'A')/6;
            int currcol=(word[i]-'A')%6;
            int dist=(abs(currrow-prevrow)+abs(currcol-prevcol));
            secondfinger=dist+solve(i+1,finger1,word[i]-'A',n,word,dp);
        }
        return dp[i][finger1+1][finger2+1] = min(firstfinger,secondfinger);
    }
    int minimumDistance(string word) {
          int n=word.length();
          vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(0,-1,-1,n,word,dp);
    }
};