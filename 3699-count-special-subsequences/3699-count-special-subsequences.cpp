class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double,int>mp;
        int n=nums.size();
        long long ans=0;
        for(int r=4;r<n-2;r++){
            int q=r-2;
            for(int p=0;p<=q-2;p++){
                double i = (1.0*nums[p])/nums[q];
                mp[i]++;
            }
            for(int s=r+2;s<n;s++){
                double j=(1.0*nums[s])/nums[r];
                if(mp.find(j)!=mp.end()){
                    ans+=mp[j];
                }
            }
        }
        return ans;
    }
};