class Solution {
public:
    int rev(int x){
        int reverse=0;
        while(x!=0){
            int r=x%10;
            reverse=reverse*10+r;
            x=x/10;
        }
        return reverse;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mod=1000000007;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int val=nums[i]-rev(nums[i]);
            if(mp.find(val)!=mp.end()){
                ans= (ans + mp[val]) % mod;
                mp[val]++;
            }
            else{
                mp[val]++;
            }
        }
        return ans;
    }
};