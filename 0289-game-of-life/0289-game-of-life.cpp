class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int livecount = 0;
                    if(j>0 && board[i][j-1]==1){
                        livecount++;
                    }
                    if(j<n-1 && board[i][j+1]==1){
                        livecount++;
                    }
                    if(i>0 && board[i-1][j]==1)
                    {
                        livecount++;
                    }
                    if(i<m-1 && board[i+1][j]==1){
                        livecount++;
                    }
                    //uperdiagonal
                    if(i>0 && j>0 && board[i-1][j-1]==1)
                        livecount++;
                    if(i>0 && j<n-1 && board[i-1][j+1]==1){
                        livecount++;
                    }
                    //lowerdiagonal
                    if(i<m-1 && j>0 && board[i+1][j-1]==1)
                        livecount++;
                    if(i<m-1 && j<n-1 && board[i+1][j+1]==1)
                        livecount++;
                    
                    if(board[i][j]==1){
                        if(livecount < 2 || livecount >3)
                            ans[i][j]=0;
                        else{
                            ans[i][j]=1;
                        }
                    }
                    else{
                        if(livecount==3){
                            ans[i][j]=1;
                        }
                        else{
                            ans[i][j]=0;
                        }
                    }
                }   
            }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=ans[i][j];
            }
        }
    
    }
};
