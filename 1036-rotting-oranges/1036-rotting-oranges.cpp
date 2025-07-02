class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        int total_oranges=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]!=0)
                {
                    total_oranges++;
                }
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
            }
        }
        int count=0;
        int minutes=0;
        while(!q.empty())
        {
            int n=q.size();
            count+=n;
             while(n--)
             {
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                for(auto &dir : directions) {
                    int new_i = p.first  + dir[0];
                    int new_j = p.second + dir[1];

                    if(new_i >= 0 && new_i < row && new_j >= 0 && new_j < col &&  grid[new_i][new_j]==1) {
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 2; //marking it as visited
                    }
                }
             }
            if(!q.empty())
                 minutes++;
        }
        return total_oranges==count?minutes:-1;
    }
};