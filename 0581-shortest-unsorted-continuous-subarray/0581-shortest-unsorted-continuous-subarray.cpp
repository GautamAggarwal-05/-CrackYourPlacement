class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<n){
            if(i<n-1 && nums[i]>nums[i+1]){
                // i decided
                break;
            }
            i++;
        }
        while(j>=0){
            if(j>0 && nums[j]<nums[j-1]){
                //j decided
                break;
            }
            j--;
        }
        if (i > j) return 0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            mini = min(mini,nums[k]);
            maxi = max(maxi,nums[k]);
        }
        int s=i;
        int e=j;
        for(int k=0;k<i;k++){
            if(nums[k]>mini){
                s=k;
                break;
            }
        }
        for(int k=n-1;k>j;k--){
            if(nums[k]<maxi){
                e=k;
                break;
            }
        }
        return e-s+1;
        
    }
};