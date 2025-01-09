class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        cout<<board[0][0]-'0'<<endl;
        for(int i=0;i<9;i++){
            //all rows check;
            vector<bool>checkrow(9,false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                if(checkrow[board[i][j]-'1']==true)
                    return false;
                else{
                    checkrow[board[i][j]-'1']=true;
                }
            }
            //all col check
            vector<bool>checkcol(9,false);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                if(checkcol[board[j][i]-'1']==true)
                    return false;
                else{
                    checkcol[board[j][i]-'1']=true;
                }
            }
        }
        
        //per block check
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int>blockcheck(9,false);
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.')
                            continue;
                        if(blockcheck[board[k][l]-'1']==true)
                            return false;
                        else
                            blockcheck[board[k][l]-'1']=true;
                    }
                }
            }
        }
        return true;
    }
};