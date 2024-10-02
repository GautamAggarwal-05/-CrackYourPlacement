class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int low=j+1;
                int high=n-1;
                while(low<=high){
                    int mid = low+(high-low)/2;
                    if(nums[mid]>=nums[i]+nums[j]){
                        high=mid-1;
                    }
                    else {
                        low=mid+1;
                    }
                }
                ans+=low-j-1;
            }
        }
        return ans;
    }
};