class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxheap;
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            maxheap.push({nums[i],i});
        }
        while(!maxheap.empty() && k!=0){
            pair<int,int>top = maxheap.top();
            maxheap.pop();
            ans.push_back({top.second,top.first});
            k--;
        }
        sort(ans.begin(),ans.end());
        vector<int>result;
        for(auto elem:ans){
            result.push_back(elem.second);
        }
        return result;
    }
};