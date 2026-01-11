class Solution {
public:
    int solve(int i,int diff,vector<int>&rods,vector<vector<int>>&dp){ // diff = l - r
       /*
        left - right = diff // doing nothing
        (left + x) - right => diff+x // add to left side
        left - (right + x) => diff - x // add to right side 
        find maximum of all 3 conditions;
       */

       if(i>=rods.size()){
        if(diff == 0)
            return 0;
        return INT_MIN;
       }

       if(dp[i][diff+5000]!=INT_MAX)
        return dp[i][diff+5000];

       int nothing = solve(i+1,diff,rods,dp);
       int add_left_rod = rods[i] +  solve(i+1,diff+rods[i],rods,dp);
       int add_right_rod = rods[i] + solve(i+1,diff-rods[i],rods,dp);

       return dp[i][diff+5000] =  max({nothing,add_left_rod,add_right_rod});
    }
    int tallestBillboard(vector<int>& rods) {
        // leftsum 
        //rightsum
        // do not take
        int n = rods.size(); 
        int sum = accumulate(rods.begin(),rods.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(10000+1,INT_MAX));
        return solve(0,0,rods,dp)/2;
    }
};