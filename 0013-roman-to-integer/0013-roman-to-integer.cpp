class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int n=s.length();
        int j=n-2;
        int ans=0;
        for(int i=n-1;i>=0;)
        {
            if(j>=0 && mp[s[i]] > mp[s[j]])
            {
                ans+=(mp[s[i]]-mp[s[j]]);
                i=j-1;
                j=i-1;
            }
            else
            {
                ans+=mp[s[i]];
                i--;
                j--;
            }
        }
        return ans;
    }
};