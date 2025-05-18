class Solution {
public:
    /*
     00-no color
     01-red
     10-green
     11-blue
     1 color takes 2 bit to reprsent itself
     3->11
    */
    int mod=1e9+7;
    int solve(int m,int n,int r,int c,int curr_state,int prev_state,vector<vector<int>>&dp){
        if(c==n){
            return 1;
        }
        if(r==m)
            return solve(m,n,0,c+1,0,curr_state,dp);
        if(r==0 && dp[c][prev_state]!=-1)
            return dp[c][prev_state];
        
        int up_color=curr_state & 3;
        int left_color = prev_state>>((m-r-1)*2) & 3; // right shift the prev state by remaining rows and we get to the    current row then and with 3 and we get which color number it is.
        int ways=0;
        for(int color=1;color<=3;color++){
            if(color!=up_color && color!=left_color){
                ways= (ways + solve(m,n,r+1,c,(curr_state<<2)+color,prev_state,dp))%mod;// left shift currstate by 2 and add curr color in place to those 2 empty space this way we are creating a state like RGB+R=RGBR 011011+01->01101101
            }
        }
        return dp[c][prev_state]=ways;
    }
    int colorTheGrid(int m, int n) {
        vector<vector<int>>dp(1023+2,vector<int>(1000,-1));
        return solve(m,n,0,0,0,0,dp);
    }
};