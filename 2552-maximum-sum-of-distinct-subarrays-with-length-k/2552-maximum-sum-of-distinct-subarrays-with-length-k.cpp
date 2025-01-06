class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long ans = 0;
        long long sum=0;
        int n = nums.size();
        int e=0;
        int s=0;
        int temp=k;
        for(int i=0;i<n;i++){
            sum += nums[e];
            mp[nums[e]]++;
            while((e-s+1)>k || mp[nums[e]]>1){
                sum -= nums[s];
                mp[nums[s]]--;
                s++;
            }
            if((e-s+1)==k)
                ans=max(ans,sum);
            
            e++;
        }
        return ans;
    }
};