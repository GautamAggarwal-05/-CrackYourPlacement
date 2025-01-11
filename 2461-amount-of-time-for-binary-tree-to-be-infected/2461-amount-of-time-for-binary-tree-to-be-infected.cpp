/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(int n,unordered_map<int,list<int>>adj,int src){
        cout<<size;
        vector<int>distance(size+1,-1);
        distance[src]=0;
        queue<int>q;
        q.push(src);
        int maxi=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neigh : adj[node]){
                if(distance[neigh]==-1){
                    q.push(neigh);
                    distance[neigh] = distance[node]+1;
                    if(maxi<distance[neigh]){
                        maxi=distance[neigh];
                    }
                }
            }
        }
            return maxi;
    }
    int size=INT_MIN;
    void makegraphfromtree(TreeNode* root,unordered_map<int,list<int>>&adj){
        if(root==NULL)
            return;
        size=max(size,root->val);
        if (root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            makegraphfromtree(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            makegraphfromtree(root->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,list<int>>adj;
        makegraphfromtree(root,adj);
        return solve(adj.size(),adj,start);
    }
};