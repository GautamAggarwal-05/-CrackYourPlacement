class Solution {
public:
    bool issafe(int row,int col,vector<string>board,int n){
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(j>=0){
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        i=row,j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int col,int n,vector<string>board,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};