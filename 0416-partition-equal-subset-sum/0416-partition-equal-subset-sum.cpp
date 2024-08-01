class Solution {
private:

//RECURSION+MEMO
// int solve(int indx, vector<int>nums, int target,vector<vector<int>>&dp)
// {
//     if(indx==nums.size()&& target!=0)
//         return false;
//     if(target==0)
//         return true;
//     if(target<0)
//         return false;
//     if(dp[indx][target]!=-1)
//         return dp[indx][target];
    
//     bool include = solve(indx+1,nums,target-nums[indx],dp);
//     bool exclude = solve(indx+1,nums,target,dp);
//     return dp[indx][target] = include or exclude;

// }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        // int target=sum/2;
        if(sum % 2!=0)
            return false;
        if(n==1)
            return false;
        
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solve(0,nums,target,dp);
        vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,0));
        for(int i=0;i<=n;i++)
             dp[i][0]=1;
        
        for(int indx=n-1 ;indx>=0;indx--)
        {
            for(int target=0;target<=sum/2;target++)
            {
                bool include=false;
                if(target-nums[indx]>=0)
                    include = dp[indx+1][target-nums[indx]];

                bool exclude = dp[indx+1][target];
                dp[indx][target] = include or exclude;
            }
        }
        return dp[0][sum/2];
    }
};

