class Solution {
public:
    bool isValid(vector<int>& nums,int i,int j,int n){
        // i to j while checking for increasing
        for(int k=1;k<i;k++){
            if(nums[k]<=nums[k-1])
                return false;
        }
        for(int k=j+2;k<n;k++){
            if(nums[k]<=nums[k-1])
                return false;
        }
        if(i-1>=0 && j+1<n && nums[j+1]<=nums[i-1])
            return false;
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isValid(nums,i,j,n))
                    count++;
            }
        }
        return count;
    }
};