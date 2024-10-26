class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=0;
        int sum=0;
        int ans=INT_MAX ;
        while(e<n){
           sum+=nums[e];
           while(s<=e && sum>=target){
            ans=min(ans,e-s+1);
            sum-=nums[s];
            s++;
           }
           e++;
        }
        return ans==INT_MAX?0:ans;
    }
};