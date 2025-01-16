class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        int a=0;
        if(n==1)
            return 0;
        int prev=0;
        int curr=0;
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        for(int i=0;i<n;i++){
            prev += (i*nums[i]);
        }
        maxi=max(maxi,prev);
        for(int i=1;i<n;i++){
            curr = (prev+sum)-n*nums[n-i];
            maxi=max(maxi,curr);
            prev=curr;
        }
        return maxi;
    }
};