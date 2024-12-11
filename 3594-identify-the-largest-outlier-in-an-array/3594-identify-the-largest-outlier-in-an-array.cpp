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