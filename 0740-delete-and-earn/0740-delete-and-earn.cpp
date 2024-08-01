class Solution {
public:
    int solve(int index,vector<int>& nums,unordered_map<int,int>& mp,vector<int>& dp)
    {
        if(index>=nums.size())
           return 0;
        if(dp[index]!=-1)
           return dp[index];
        
        int exclude=solve(index+1,nums,mp,dp);
    
        int include=mp[nums[index]]*nums[index]+solve(index+mp[nums[index]]+mp[nums[index]-1],nums,mp,dp);

        return dp[index]= max(include,exclude);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
       
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,mp,dp);
    }
};