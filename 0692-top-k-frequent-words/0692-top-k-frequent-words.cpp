class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b){
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first < b.first; 
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto str:words){
            mp[str]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto elem:mp){
            pq.push({elem.second,elem.first});
        }
        vector<string>result;
        while(!pq.empty() && k!=0){
            pair<int,string>top = pq.top();
            pq.pop();
            k--;
            result.push_back(top.second);
        }
        return result;
    }
};