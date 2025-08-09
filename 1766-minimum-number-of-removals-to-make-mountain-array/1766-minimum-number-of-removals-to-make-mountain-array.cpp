class Solution {
public:

    vector<int> getLIS(vector<int>&nums){
        vector<int>lisLenAtEachIndex(nums.size(),1);

        vector<int>lis={nums[0]};

        for(int i=1;i<nums.size();i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
            }else{
                int indx = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[indx]=nums[i];
            }
            lisLenAtEachIndex[i]=lis.size();
        }
        return lisLenAtEachIndex;
        
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        
        // we want longest Increasing subsequence at each index we are going up 0->i the moutain
        vector<int>lis=getLIS(nums);

        // we want longest decreasing subsequence at each index we are going down i->n the moutain
        reverse(nums.begin(),nums.end());
        vector<int>lds=getLIS(nums);
        // right now   if we use lds [i] it means descreasing array from 0->i but we wanted i->n-1 so we reverse the array
        reverse(lds.begin(),lds.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
                ans = min(ans,n-lis[i]-lds[i]+1);
            }
        }
        return ans;
    }
};