class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int e=0;
        int s=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        long long maxi=0;
        long long sum=0;
        while(e<n){
            sum+=nums[e];
            mp[nums[e]]++;
            while((e-s+1)>k || mp[nums[e]]>1){
                mp[nums[s]]--;
                sum -= nums[s];
                s++;

        }
        if((e-s+1) == k)
            maxi=max(maxi,sum);
        e++;
        }
        return maxi;
    }
};