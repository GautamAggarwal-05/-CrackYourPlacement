class Solution {
public:
    vector<vector<unordered_map<int,int>>>dp;

    int solve(int i,int j,int currand,int n,int m,vector<int>& nums, vector<int>& andValues){

        if(i==n){
            return j==m?0:1e7;
        }
        if(j==m)
            return 1e7;

        if(dp[i][j].count(currand)>0){
            return dp[i][j][currand];
        }

        int include=1e7;
        if((nums[i] & currand) == andValues[j]){
            include = nums[i]+solve(i+1,j+1,(1<<20)-1,n,m,nums,andValues);
        }
        int exclude = solve(i+1,j,(nums[i]&currand),n,m,nums,andValues);
        return dp[i][j][currand] = min(include,exclude);
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        dp.resize(n,vector<unordered_map<int,int>>(10));
        int ans =  solve(0,0,(1<<20)-1,n,m,nums,andValues);
        return ans==1e7?-1:ans;
    }
};