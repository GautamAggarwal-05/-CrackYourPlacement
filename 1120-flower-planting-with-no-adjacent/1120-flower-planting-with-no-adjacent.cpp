class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, list<int>> adj;

        for(auto& path : paths) {
            int u = path[0] - 1;  
            int v = path[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> flower(n, 0);  
        
        // Assign flower types
        for(int i = 0; i < n; i++) {
            // Track flower types used by neighbors
            vector<bool> used(5, false); 
            
            for(int neighbor : adj[i]) {
                if(flower[neighbor] != 0) {
                    used[flower[neighbor]] = true;
                }
            }

            // Assign the first available flower type
            for(int f = 1; f <= 4; f++) {
                if(!used[f]) {
                    flower[i] = f;
                    break;
                }
            }
        }
        
        return flower;
    }
};
