class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(auto num:nums)
        // {
        //     mp[num]++;
        // }
        // for(auto val:mp)
        // {
        //     if(val.second > 1)
        //         result.push_back(val.first);
        // }

        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1] < 0)
                result.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1]*=-1;
        }
        return result;
    }
};