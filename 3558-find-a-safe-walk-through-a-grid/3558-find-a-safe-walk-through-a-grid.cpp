class Solution {
public:
    
    bool solve(int i,int j,int m,int n,vector<vector<int>>&grid,int health,vector<vector<vector<int>>>& dp){
        if(grid[i][j]==1){
            health--;
        }
        if(i==m-1 && j==n-1 && health>=1){
            return true;
        }
        if(health < 1)
            return false;
        
        if(dp[i][j][health]!=-1){
            return dp[i][j][health];
        }
        
        int originalValue = grid[i][j];
        grid[i][j] = -1;
        bool down=false,right=false,up=false,left=false;
        if(i+1<m && grid[i+1][j]!=-1)
            down = solve(i+1,j,m,n,grid,health,dp);

        if(j+1<n && grid[i][j+1]!=-1)
            right = solve(i,j+1,m,n,grid,health,dp);

        if(i-1>=0 && grid[i-1][j]!=-1)
            up = solve(i-1,j,m,n,grid,health,dp);

        if(j-1>=0 && grid[i][j-1]!=-1)
            left = solve(i,j-1,m,n,grid,health,dp);

        grid[i][j]=originalValue; 
        return dp[i][j][health] = down || right || up || left;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1,     -1)));
        return solve(0,0,m,n,grid,health,dp);
    }
};