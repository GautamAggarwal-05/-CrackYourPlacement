class Solution {
struct comp{
    bool operator()(pair<int,int>&a , pair<int,int>b){
        if(a.second==b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(auto num:nums){
            map[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;

        for(auto elem:map){
            pq.push({elem.first,elem.second});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};