// Recursion + Memoization
class Solution {
public:
    int ans=0;
    // Very Simple Recursive Approach : Done
    int solve(vector<int>&nums1, vector<int>&nums2, int i, int j,vector<vector<int>>&dp)
    {
        if(i>=nums1.size() or j>=nums2.size()) 
            return 0;  
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        ans = nums1[i]*nums2[j] + solve(nums1, nums2, i+1, j+1,dp);
        ans = max({ans,solve(nums1,nums2,i+1,j,dp),solve(nums1, nums2, i, j+1,dp)});
        return dp[i][j] = ans;
    }
   
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // int ans=0;
        solve(nums1,nums2,0,0,dp);
    
        if(ans==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }
        return ans;
    }
};