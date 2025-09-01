class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int>mp;
        int n = order.size();
        for(int i=0;i<n;i++){
            mp[order[i]]=i;
        }

        vector<pair<int,int>>frnd;
        for(auto x:friends){
            frnd.push_back({mp[x],x});
        }
        sort(frnd.begin(),frnd.end());
        vector<int>result;
        for(auto x:frnd){
            result.push_back(x.second);
        }
        return result;
    }
};