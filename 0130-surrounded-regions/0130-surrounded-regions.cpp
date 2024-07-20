class Solution 
{
public:
    void check(int r,int c,vector<vector<char>>&board)
    {
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() ||board[r][c]!='O')
        {
          return;
        }
        board[r][c]='T';
        check(r+1,c,board);
        check(r-1,c,board);
        check(r,c+1,board);
        check(r,c-1,board);
    }
    void solve(vector<vector<char>>& board) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
               if(i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1)
               {
                check(i,j,board);
               }
            }
        }
        
        for(int r=0;r<board.size();r++)
        {
            for(int c=0;c<board[0].size();c++)
            {
                if(board[r][c]=='T')
                {
                    board[r][c]='O';
                }
                else if(board[r][c]=='O')
                {
                    board[r][c]='X';
                }
            }
        }
    }
};