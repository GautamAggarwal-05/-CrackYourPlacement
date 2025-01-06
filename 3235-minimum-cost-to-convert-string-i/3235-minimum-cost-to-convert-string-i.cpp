class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int CHAR_COUNT = 26;
        const int INF = 1e9;
        vector<vector<int>> graph(CHAR_COUNT, vector<int>(CHAR_COUNT, INF));
        
        // Initialize graph diagonal (cost to convert a char to itself is 0)
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }

        // Fill the conversion graph with costs
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';  
            int to = changed[i] - 'a';    
            graph[from][to] = min(graph[from][to], cost[i]);  // Take minimum cost if multiple conversions exist
        }

        // Apply Floyd-Warshall algorithm
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                for (int j = 0; j < CHAR_COUNT; j++) {
                    if (graph[i][k] < INF && graph[k][j] < INF) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a'; 
            int targetChar = target[i] - 'a';  
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;  
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }
};