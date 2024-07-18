class Solution {
    void solve(int i,vector<int>nums,vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(nums);
        }

        for(int j=i;j<nums.size();j++){
            if(nums[i]!=nums[j]||i==j){
                swap(nums[j],nums[i]);
                solve(i+1,nums,ans);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans);
        return ans;
    }
};