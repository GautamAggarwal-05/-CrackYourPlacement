class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        vector<int>dp(maxi+2,0);
        for(auto elem:nums){
            dp[elem+1]=dp[elem]+1;
            dp[elem]=dp[elem-1]+1;
        }
        int ans=0;
        for(auto elem:dp){
            ans=max(ans,elem);
        }
        return ans;
    }
};