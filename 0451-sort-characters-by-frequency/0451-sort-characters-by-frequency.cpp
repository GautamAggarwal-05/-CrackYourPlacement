class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<int,int>>freq;
        for(auto elem:mp){
            freq.push_back({elem.second,elem.first});
        }
        sort(freq.begin(),freq.end());
        for(auto elem : freq){
            for(int i=0;i<elem.first;i++){
                ans.push_back(elem.second);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};