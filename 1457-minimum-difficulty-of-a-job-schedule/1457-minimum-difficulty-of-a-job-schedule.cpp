class Solution {
public:
    int solve(int i,int d,int n,vector<int>& arr,vector<vector<int>>&dp){
        if(d==1){
            int maxi=arr[i];
            for(int indx=i;indx<n;indx++){
                maxi=max(maxi,arr[indx]);
            }
            return maxi;
        }
        if(dp[i][d]!=-1)
            return dp[i][d];
        int maxD=arr[i];
        int res=INT_MAX;
        int ans=0;
        for(int indx=i;indx<=n-d;indx++){
            maxD=max(maxD,arr[indx]);
            ans=maxD+solve(indx+1,d-1,n,arr,dp);
            res = min(ans,res);
        }
        return dp[i][d] = res;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(n<d)
            return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        int ans=solve(0,d,n,arr,dp);
        return ans;
    }
};