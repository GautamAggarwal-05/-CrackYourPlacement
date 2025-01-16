class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans=0;
        if(k==0){
            for(auto elem:mp){
                if(elem.second>1)
                    ans ++;
            }
            return ans;
        }
        for(auto elem:mp){
            int found = elem.first+k;
            cout<<found;
            if(mp.find(found)!=mp.end()){
                ans++;
            }
        }
        return ans;
    }
};