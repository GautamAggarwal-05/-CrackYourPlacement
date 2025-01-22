class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int s=0,e=0;
        int ans=0;
        while(e<n){
            mp[nums[e]]++;
            while(s<=e && mp[nums[e]]>k){
                mp[nums[s]]--;
                s++;
            }
            ans = max(ans,(e-s+1));
            e++;
        }
        return ans;
    }
};