class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=INT_MIN;
        int n = s.length();
        for(int i=0;i<n;i++){
            vector<int>hash(26,0);
            int maxf=0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxf = max(maxf,hash[s[j]-'A']);
                int changes = (j-i+1) - maxf;
                if(changes<=k){
                    ans = max(ans,j-i+1);
                }
                else
                    break;
            }
        }
        return ans;
    }
};