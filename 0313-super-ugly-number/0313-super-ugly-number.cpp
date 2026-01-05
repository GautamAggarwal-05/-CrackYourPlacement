class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>pointers(primes.size()+1,1);
        vector<long long>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            long long val=LLONG_MAX;
            for(int j=0;j<primes.size();j++){
                val = min(val,1LL*primes[j]*dp[pointers[j]]);
            }

            for(int j=0;j<primes.size();j++){
                if (val == 1LL*primes[j]*dp[pointers[j]]){
                    pointers[j]++;
                }
            }
            dp[i]=val;
        }
        return dp[n];
    }
};