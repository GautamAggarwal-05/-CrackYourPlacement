class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        int n=s.length();
        vector<string>ans;
        for(int i=0;i<=n-10;i++){
            string str = s.substr(i,10);
            mp[str]++;
        }
        for(auto elem:mp){
            if(elem.second>1)
                ans.push_back(elem.first);
        }
        return ans;
    }
};

