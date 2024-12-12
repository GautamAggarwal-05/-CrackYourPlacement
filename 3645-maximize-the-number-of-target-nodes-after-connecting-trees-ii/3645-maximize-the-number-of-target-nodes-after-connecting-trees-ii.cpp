class Solution {
public:
        unordered_map<int,list<int>> adj1;
        unordered_map<int,list<int>> adj2;
        vector<int> evenSubtree1,oddSubtree1,totalEven1,totalOdd1;
        vector<int> evenSubtree2,oddSubtree2,totalEven2,totalOdd2;

        void dfs1Tree1(int node,int parent){
            evenSubtree1[node]=1;
            oddSubtree1[node]=0;

            for(int ne:adj1[node]){
                if(ne!=parent){
                    dfs1Tree1(ne,node);
                    evenSubtree1[node]+=oddSubtree1[ne];
                    oddSubtree1[node]+=evenSubtree1[ne];
                }
            }
        }

        void dfs2Tree1(int node,int parent,int evenAbove,int oddAbove){
            totalEven1[node]=evenSubtree1[node]+evenAbove;
            totalOdd1[node]=oddSubtree1[node]+oddAbove;

            for(int ne:adj1[node]){
                if(ne!=parent){
                    int evenUp=totalOdd1[node]-evenSubtree1[ne];
                    int oddUp=totalEven1[node]-oddSubtree1[ne];

                    dfs2Tree1(ne,node,evenUp,oddUp);
                }
            }
        }
        void dfs1Tree2(int node, int parent) {
            evenSubtree2[node] = 1; 
            oddSubtree2[node] = 0;
            for (int ne : adj2[node]) {
                if (ne != parent) {
                    dfs1Tree2(ne, node);
                    evenSubtree2[node] += oddSubtree2[ne];
                    oddSubtree2[node] += evenSubtree2[ne];
                }
            }
        }

        void dfs2Tree2(int node, int parent, int evenAbove, int oddAbove) {
            totalEven2[node] = evenSubtree2[node] + evenAbove;
            totalOdd2[node] = oddSubtree2[node] + oddAbove;

            for (int ne : adj2[node]) {
                if (ne != parent) {
                    int evenUp = totalOdd2[node] - evenSubtree2[ne];
                    int oddUp = totalEven2[node] - oddSubtree2[ne];

                    dfs2Tree2(ne, node, evenUp, oddUp);
                }
            }
        }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n=edges1.size()+1;
        int m=edges2.size()+1;
        for(int i=0;i<edges1.size();i++){
            int u=edges1[i][0];
            int v=edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i=0;i<edges2.size();i++){
            int u=edges2[i][0];
            int v=edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        evenSubtree1.resize(n);
        oddSubtree1.resize(n);
        totalEven1.resize(n);
        totalOdd1.resize(n);
        dfs1Tree1(0, -1);
        dfs2Tree1(0, -1, 0, 0);

        evenSubtree2.resize(m);
        oddSubtree2.resize(m);
        totalEven2.resize(m);
        totalOdd2.resize(m);
        dfs1Tree2(0, -1);
        dfs2Tree2(0, -1, 0, 0);


        int maxi=totalOdd2[0];

        for(int i=1;i<m;i++){
            maxi=max(maxi,totalOdd2[i]);
        }

        vector<int> answer(n);

        for(int i=0;i<n;i++){
            answer[i]=totalEven1[i]+maxi;
        }

        return answer;
        
    }
};