class Solution {
public:
    void dfs(int src,unordered_map<int,list<int>>&adj,vector<int>&nums,vector<bool>&visited){
        visited[src+100000]=true;
        nums.push_back(src);
        for(auto neigh:adj[src]){
            if(!visited[neigh+100000]){
                dfs(neigh,adj,nums,visited);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<adjacentPairs.size();i++){
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int src;
        vector<int>nums;
        vector<bool>visited(200001,false);
        for(auto elem :adj){
            if(elem.second.size()==1){
                src=elem.first;
                break;
            }
        }
        dfs(src,adj,nums,visited);
        return nums;
    }
};