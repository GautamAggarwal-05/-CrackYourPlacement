class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // make all zeros 1 and check when it happens
        int n = grid.size();
        
        int m = grid[0].size();
        
        vector<int> dx = {-1, 0, 1, 0};
        
        vector<int> dy = {0, 1, 0, -1};
        
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i, j});
                }
            }
        }
        
        // if no. of 0 in grid is 0
        
        if(q.size() == n * m)
            return -1;
        
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                auto curr = q.front();
            
                q.pop();
            
                int i = curr.first;
             
                int j = curr.second;
            
                // check all 4 directions
            
                for(int k = 0; k < 4; k++)
                {
                    int new_i = i + dx[k];
                
                    int new_j = j + dy[k];
                
                    if(new_i >= 0 && new_i < n && new_j >= 0 && grid[new_i][new_j] == 0)
                    {
                        q.push({new_i, new_j});
                        
                        grid[new_i][new_j] = 1;
                    }
                }
            }
            
            dist++;
        }
        
        return dist - 1;
    }
};