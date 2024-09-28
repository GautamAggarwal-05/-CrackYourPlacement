class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int sum=0;
            while(n!=0){
                int r=n%10;
                sum+=r;
                n=n/10;
            }
            ans=min(ans,sum);
        }

        return ans;
    }
};