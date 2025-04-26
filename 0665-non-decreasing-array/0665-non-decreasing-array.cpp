class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(count>1)
                return false;
            if(nums[i]>nums[i+1]){
                if(i==n-2 && count==0)
                    return true;
                if(i!=0 && i<n-2 && nums[i+1]<nums[i-1] && nums[i+2]<nums[i])
                    return false;
                count++;
            }
        }
        if(count>=1 && nums[n-1]<nums[n-2])
            return false;
        return true;
    }
};