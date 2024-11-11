class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]].second=i;
            }
            else
                mp[s[i]]={i,i};
        }
        int ans=0;
        for(auto elem = mp.begin() ; elem != mp.end() ; elem++){
            unordered_set<int>unique;
            if((elem->second.second - elem->second.first) > 1){
                for(int j=elem->second.first+1;j<elem->second.second;j++){
                    unique.insert(s[j]);
                }
            }
            ans += unique.size();
        }
        return ans;
    }
};