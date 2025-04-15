class Solution {
public:
    bool solve(int i,int jump,vector<int>& stones,vector<vector<int>>& dp){
        if(i==stones.size()-1)
            return true;
        if(i>=stones.size())
            return false;
        if(jump<=0)
            return false;
        if(mp.find(stones[i]+jump)==mp.end()){
            return false;
        }
        if(dp[i][jump]!=-1)
            return dp[i][jump];

        int indx=mp[stones[i]+jump];
        bool back = solve(indx,jump-1,stones,dp);
        bool curr = solve(indx,jump,stones,dp);
        bool forward=solve(indx,jump+1,stones,dp);
        return dp[i][jump] = back || curr || forward;
    }
    unordered_map<int,int>mp;
    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return solve(0,1,stones,dp);
    }
};