class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>map;
        vector<vector<string>>res;
        for(int itr=0;itr<strs.size();itr++){
            string temp=strs[itr];
            sort(temp.begin(),temp.end());
            if(map.find(temp)!=map.end()){
                res[map[temp]].push_back(strs[itr]);
            }
            else{
                map[temp]=res.size();
                res.push_back({strs[itr]});
            }
        }
        return res;
    }
};