class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        int largestoutlier=INT_MIN;
        // n-2 number sum + sum we are finding = 2*sum we are finding
        // 2 * specialnumber = (totalsum-outlier); specialnumber is the sum we are trying to make with n-2 numbers
        for(int i=0;i<n;i++){
            int outlier=nums[i];
            int reqsum = sum-outlier;
            if(reqsum%2!=0) continue;
            int specialnumber = reqsum/2;
            mp[outlier]--;
            if(mp.find(specialnumber)!=mp.end() && mp[specialnumber]>0){
                largestoutlier = max(largestoutlier,outlier);
            }
            mp[outlier]++;
        }
        return largestoutlier;
    }
};