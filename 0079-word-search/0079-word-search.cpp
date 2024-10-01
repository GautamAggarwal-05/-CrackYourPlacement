class Solution {
public:
    bool solve(int i,int j,int indx,int n,int m,vector<vector<char>>& board,string &word, vector<vector<int>>&visited){
        if(indx==word.length())
            return true;
        
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || board[i][j] != word[indx])
            return false;
        visited[i][j]=true;
        bool left=false,right=false,up=false,down=false;
        up = solve(i-1,j,indx+1,n,m,board,word,visited);
        down = solve(i+1,j,indx+1,n,m,board,word,visited);
        left = solve(i,j-1,indx+1,n,m,board,word,visited);
        right = solve(i,j+1,indx+1,n,m,board,word,visited);     
        visited[i][j]=false;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,false));
        string temp="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,0,n,m,board,word,visited))
                    return true;
            }
        }
         return false;
    }
};