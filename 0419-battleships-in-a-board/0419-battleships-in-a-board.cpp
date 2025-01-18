class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.')
            return;
        board[i][j]='.';
        dfs(i+1,j,n,m,board);
        dfs(i,j+1,n,m,board);
        dfs(i-1,j,n,m,board);
        dfs(i,j-1,n,m,board);

    }
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,n,m,board);
                    ans++;
                }
            }
        }
        return ans;
    }
};