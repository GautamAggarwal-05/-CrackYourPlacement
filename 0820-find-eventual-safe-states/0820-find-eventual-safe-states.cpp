class Solution {
    bool dfs(int u,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&inrecursion){
        visited[u]=true;
        inrecursion[u]=true;
        for(auto v:graph[u]){
            if(!visited[v] && dfs(v,graph,visited,inrecursion)){
                return true;
            }
            else if(inrecursion[v]==true){
                return true;
            }
        }
        inrecursion[u]=false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,inrecursion);
            }
        }
        vector<int>ans;
        for(int i=0;i<inrecursion.size();i++){
            if(!inrecursion[i]){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};