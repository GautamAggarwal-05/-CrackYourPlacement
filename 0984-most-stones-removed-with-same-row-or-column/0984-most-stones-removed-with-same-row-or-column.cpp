class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        int n = stones.size();
        
        // Find maximum row and column index
        for (int i = 0; i < n; i++) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        // Create a disjoint set large enough to handle both rows and columns
        DisjointSet ds(maxRow + maxCol + 1);  // size should be maxRow + maxCol

        // Union rows and columns by shifting the column index
        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            int col = stones[i][1] + maxRow + 1;  // shift column index by maxRow + 1
            ds.unionByRank(row, col);
        }

        // Count how many unique components are there
        unordered_set<int> uniqueParents; // to store distinct connected components
        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            uniqueParents.insert(ds.findUPar(row));  // find the representative of the row
        }

        // Result is the number of stones that can be removed
        return n - uniqueParents.size();
    }
};
