class Solution {
public:
    int solve(int e,int f,vector<vector<int>>&dp){
        if(f==1||f==0)
            return f;
        if(e==1)
            return f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];

        int ans=INT_MAX;
        int l=1,h=f;
        while(l<=h){
            int mid = l+(h-l)/2;
            int left = solve(e-1,mid-1,dp);
            int right = solve(e,f-mid,dp);
            
            if(left<right)
                l=mid+1;
            else
                h=mid-1;
            ans = min(ans,1+max(left,right));
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};