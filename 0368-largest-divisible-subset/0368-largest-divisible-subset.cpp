class Solution {
public:
    

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>prev_indx(n,-1);
        int lastchosenindex=0;
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev_indx[i]=j;
                    }
                    if(dp[i]>maxi){
                        maxi=dp[i];
                        lastchosenindex = i;
                    }
                }
            }
        }
        vector<int>result;
        while(lastchosenindex!=-1){
            result.push_back(nums[lastchosenindex]);
            lastchosenindex=prev_indx[lastchosenindex];
        }
        return result;
    }
};
