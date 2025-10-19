class Solution {
public:
    int solve(int i,int uniquechar,bool canchange,string& s,int k,unordered_map<long long,int>&dp){
        if(i>=s.length())
            return 1;// whole string is partiton in itself
        long long key = (((long long)i<<27) | (uniquechar<<1) | canchange );
        if(dp.count(key)>0){
            return dp[key];
        }

        int charindex=s[i]-'a';
        int updatedunique=uniquechar | (1<<charindex);
        int uniquecount = __builtin_popcount(updatedunique);
        int result;
        if(uniquecount>k){// we can do partiton
            result = 1+solve(i+1,(1<<charindex),canchange,s,k,dp); 
        }
        else{
            result = solve(i+1,updatedunique,canchange,s,k,dp);
        }

        if(canchange){
            for(int newcharindex = 0; newcharindex<26;newcharindex++){
                int newunique = uniquechar | (1<<newcharindex);
                int newcount = __builtin_popcount(newunique);
                if(newcount>k){// we can do partiton
                    result = max(result, 1+solve(i+1,(1<<newcharindex),false,s,k,dp)); 
                }
                else{
                    result = max(result,solve(i+1,newunique,false,s,k,dp));
                }
            }
        }
        return dp[key] = result;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long,int>dp;
        return solve(0,0,true, s, k,dp);
    }
};