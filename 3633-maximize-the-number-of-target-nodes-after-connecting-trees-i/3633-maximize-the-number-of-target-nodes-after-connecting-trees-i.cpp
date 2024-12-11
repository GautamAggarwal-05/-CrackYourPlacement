class Solution {
public:
    int bfsCount(unordered_map<int,list<int>>&adj,int src,int k,int size){
        vector<int>visited(size);
        queue<int>q;
        q.push(src);
        visited[src]=true;
        int count=0,dist=0;
        while(!q.empty() && dist<=k){
            int sz=q.size();
            while(sz-->0){
                int node=q.front();
                q.pop();
                count++;
                for(auto nd:adj[node]){
                    if(!visited[nd]){
                        visited[nd]=true;
                        q.push(nd);
                    }
                }
            }
            dist++;
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,list<int>>adj1,adj2;
        int n1=edges1.size();
        int n2=edges2.size();

        for(int i=0;i<n1;i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i=0;i<n2;i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int>cnt1(n1+1);
        for(int i=0;i<=n1;i++){
            cnt1[i] = bfsCount(adj1,i,k,n1+1);
        }

        int bestnode=0;// second tree mai best node is jiss node pai near maximum nodes are present at k distance
        for(int v=0;v<=n2;v++){
            int node = bfsCount(adj2,v,k-1,n2+1);
            bestnode=max(bestnode,node);
        }

        vector<int>ans;
        for(int i=0;i<=n1;i++){
            ans.push_back(cnt1[i]+bestnode);
        }
        return ans;
    }
};