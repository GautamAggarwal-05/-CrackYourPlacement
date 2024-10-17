class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //chnaged the prespective  keeping track of ki how many people know the secret at ith day and then sum up
        // the last forgrt number of days to get our answer 
        vector<int>know(n+1,0);
        int mod=1e9+7;
        know[1]=1;
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<min(i + forget, n + 1);j++){
                know[j] = (know[j]+know[i])%mod;
            }
        }
        int ans=0;
        int j=max(1,n-forget+1);
        for(;j<=n;j++){
            ans= (ans+know[j])%mod;
        }
        return ans;
    }
};