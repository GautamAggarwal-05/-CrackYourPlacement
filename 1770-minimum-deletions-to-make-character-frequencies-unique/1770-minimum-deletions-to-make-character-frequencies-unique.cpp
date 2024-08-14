class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());
        unordered_map<int,int>mp;
        int ans=0;
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            while(mp.find(freq[i])!=mp.end()){
                freq[i]--;
                ans++;
            }
            if(freq[i]!=0)
                mp[freq[i]]++;
        }
        return ans;
    }
};