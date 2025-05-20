class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            diff[l]+=1;
            if(r+1<n)
                diff[r+1]+=-1;
        }
        vector<int>prefixsum(n);
        prefixsum[0]=diff[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+diff[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i]>prefixsum[i])
                return false;
        }
        return true;
    }
};