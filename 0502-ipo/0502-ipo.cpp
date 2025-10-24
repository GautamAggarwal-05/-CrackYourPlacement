class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Min-heap to keep track of projects based on their capital requirement
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCapitalPQ;
        // Max-heap to keep track of the available projects based on their profits
        priority_queue<int> maxProfitPQ;

        // Push all projects into the min-heap
        for (int i = 0; i < capital.size(); ++i) {
            minCapitalPQ.push({capital[i], profits[i]});
        }

        while (k > 0) {
            // Move all projects that can be started with the current capital to the max-heap
            while (!minCapitalPQ.empty() && minCapitalPQ.top().first <= w) {
                maxProfitPQ.push(minCapitalPQ.top().second);
                minCapitalPQ.pop();
            }

            // If no projects can be started, return the current capital
            if (maxProfitPQ.empty()) {
                return w;
            }

            // Start the project with the maximum profit
            w += maxProfitPQ.top();
            maxProfitPQ.pop();

            k--;
        }

        return w;
    }
};