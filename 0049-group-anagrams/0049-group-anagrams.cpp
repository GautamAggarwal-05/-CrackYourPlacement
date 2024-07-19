class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<vector<string>>res;

        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end())
            {
                res[mp[temp]].push_back(strs[i]);
            }
            else
            {
                mp[temp]=res.size();
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};

