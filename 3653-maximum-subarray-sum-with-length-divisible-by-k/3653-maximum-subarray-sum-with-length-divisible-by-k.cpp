class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long prefixsum=0;
        vector<long long> minprefixsum(k, LLONG_MAX);
        minprefixsum[k-1] = 0;
        long long maxsum = LLONG_MIN;
        for(int i=0;i<n;i++){
            prefixsum += nums[i];
            int remainder = i%k; // iss index pai jo bhi k kai divisible array length bann sakte hai unme sai minium prefix sum kiska hai peeche vo current prefix sum mai sai minus karenge to get our maxsum 
            if(i>=k){
                maxsum = max(maxsum,prefixsum-minprefixsum[remainder]);
            }
            else if(i==k-1){
                maxsum = max(maxsum,prefixsum);
            }
            minprefixsum[remainder] = min(prefixsum,minprefixsum[remainder]);
        }
        return maxsum;
    }
};