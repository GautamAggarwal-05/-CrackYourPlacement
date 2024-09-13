class Solution {
public:
    void dfs(int i,vector<bool>&visited,unordered_map<int,list<int>>&adj){
        visited[i]=true;
        for(auto neigh:adj[i]){
            if(!visited[neigh]){
                cout<<neigh<<" ";
                dfs(neigh,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n-1 > edges)
            return -1;
        int disconnected = 0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                cout<<endl;
                disconnected++;
            }
        }
        cout<<disconnected;
        return disconnected - 1;
        
    }
};