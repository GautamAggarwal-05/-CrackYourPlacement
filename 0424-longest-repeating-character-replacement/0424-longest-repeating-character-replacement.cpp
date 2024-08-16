class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=INT_MIN;
        int n = s.length();
        int l=0;
        int r=0;
        int maxf=0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            while(l<r && (r-l+1) - maxf > k){
                hash[s[l]-'A']--;
                maxf = max(maxf,hash[s[l]-'A']);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};