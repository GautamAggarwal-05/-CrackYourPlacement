class Solution {
public:
    int walled=3;
    int Guard=2;
    void dfs(int i,int j,int m,int n,vector<vector<int>>& visited,char dir){
        if(i<0 || i>= m || j<0 || j>=n || visited[i][j]==Guard || visited[i][j]==walled)
            return;
       
        visited[i][j]=1;
        //top
        if(dir == 'U')
            dfs(i-1,j,m,n,visited,'U');
        //down
        if(dir == 'D')
        dfs(i+1,j,m,n,visited,'D');
        //left
        if(dir == 'L')
        dfs(i,j-1,m,n,visited,'L');
        //right
        if(dir=='R')
        dfs(i,j+1,m,n,visited,'R');
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(auto guard:guards){
            visited[guard[0]][guard[1]]=Guard;
        }
        for(auto wall:walls){
            visited[wall[0]][wall[1]]=walled;
        }

        for(auto guard:guards){
            dfs(guard[0]-1,guard[1],m,n,visited,'U');
            dfs(guard[0] + 1, guard[1],m,n, visited, 'D');  
            dfs(guard[0], guard[1] - 1,m,n, visited, 'L');  
            dfs(guard[0], guard[1] + 1,m,n, visited, 'R');
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0)
                    count++;
            }
        }
        return count;
    }
};