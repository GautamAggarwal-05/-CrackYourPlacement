class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        int i=0;
        while(i<n){
            int j;
            int val=nums[i];
            for(j=0;j<val;j++){
                    // cout<<nums[i]<<endl;
                if((j | (j+1)) == nums[i])
                {
                    ans[i]=j;
                    break;
                }
              
            }
            i++;
        }
        return ans;
    }
};