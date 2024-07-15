https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0,j=1;j<n;i++,j++)
        {
            if(nums[i]==nums[j])
                return nums[i];
        }
        return -1;
    }
};