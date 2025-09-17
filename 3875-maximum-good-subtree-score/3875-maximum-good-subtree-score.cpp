class Solution {
public:

    int mod=1e9+7;
    int ans=0;
    vector<int>values;
    vector<vector<int>>tree;

    int getDigitMask(int val){
        int mask=0;
        while(val){
            int d = val%10;
            if(mask & (1<<d)) return -1;//digit repeated
                mask = mask | (1<<d);
            val /= 10;
        }
        return mask;
    }

    unordered_map<int,int> dfs(int node){
        unordered_map<int,int>dp;
        dp[0]=0; // empty subset

        int mask = getDigitMask(values[node]);
        // now the curr node value check if digit not repeat itself like 22
        if(mask!=-1){
            dp[mask]=values[node];
        }

        for(auto &child:tree[node]){
            // going to leaf before start merging
            auto childDp=dfs(child);
            unordered_map<int,int>newDP=dp;
            // merge child maps with parent map
            for(auto &[mask1,sum1]:dp){
                for(auto &[mask2,sum2]:childDp){
                    if( (mask1 & mask2) == 0){ // if all digits are different merge that map values
                        int combinedmask = mask1 | mask2;
                        newDP[combinedmask] = max(newDP[combinedmask],sum1+sum2);
                    }
                }
            }
            dp=newDP;
        }

        int currmax=0;
        for(auto &[mask,val]:dp){
            currmax = max(currmax,val);
        }
        ans = (ans+currmax)%mod;
        return dp;
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        values=vals;
        int n=values.size();
        tree.resize(n);
        for(int i=1;i<n;i++){
            tree[par[i]].push_back(i);
        }
        ans=0;
        dfs(0);
        return ans;
    }
};