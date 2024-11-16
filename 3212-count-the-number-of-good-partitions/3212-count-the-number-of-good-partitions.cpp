class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]].second = i;
            }
            else{
                mp[nums[i]] = {i,i};
            }
        };
        int n=nums.size();
        int count=1;
        vector<pair<int,int>>arr;
        for(auto &elem:mp){
            arr.push_back({elem.second.first,elem.second.second});
        }
        sort(arr.begin(),arr.end());
        int maxi=arr[0].second;
        for(int i=1;i<arr.size();i++){
            if(arr[i].first>maxi){
                count++;
            }
            maxi=max(maxi,arr[i].second);
        }
        int mod = 1e9+7;
        vector<int> power(arr.size(), 1);
        for (int k = 1; k < arr.size(); ++k) {
            power[k] = (power[k - 1] * 2) % mod;
        }
        return power[count-1];
    }
};