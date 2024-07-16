class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        int maxi=INT_MIN;
        int ans=0;
        for(auto it:mp)
        {
           if(it.second > maxi)
           {
               maxi=it.second;
               ans=it.first;
           }
        }
        return ans;
    }
};