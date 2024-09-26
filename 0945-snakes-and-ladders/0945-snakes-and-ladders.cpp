class Solution {
public:
    pair<int,int> getCordinates(int num,int n){
        pair<int,int>cord;
        int RT = (num-1)/n;
        int RB = (n-1) - RT;

        int col = (num-1)%n;
        if((n%2==0 && RB%2==0) || (n%2!=0 && RB%2!=0))
            col = (n-1) - col;
        
        return {RB,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        int n = board.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        q.push(1);
        int steps=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front();
                q.pop();
                if(x==n*n)
                    return steps;
                
                for(int k=1;k<=6;k++){
                    int value = x+k;
                    if(value > n*n)
                        break;
                    pair<int,int>cord = getCordinates(value,n);
                    int r = cord.first;
                    int c = cord.second;
                    if(visited[r][c])
                        continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1)
                        q.push(value);
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};