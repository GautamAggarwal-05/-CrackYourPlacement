class Solution {
public:
    int dfs(int src,unordered_map<int,list<int>>&adj,vector<int>& informTime){
        int ans=0;
        for(auto neigh:adj[src]){
        ans = max(ans,dfs(neigh,adj,informTime));
        }
        return ans+informTime[src];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int ans=0;
        return dfs(headID,adj,informTime);
    
    }
};