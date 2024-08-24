class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxQueue;
        int currentFuel = startFuel;
        int stops = 0;
        int currentPosition = 0;

        stations.push_back({target, 0});
        for(const auto & station: stations) {
            int position = station[0];
            int fuel = station[1];

            while(currentPosition + currentFuel < position) {
                if (maxQueue.empty()) {
                    return -1;
                }
                currentFuel += maxQueue.top();
                maxQueue.pop();
                stops++;
            }
            currentFuel -= (position - currentPosition);
            currentPosition = position;

            maxQueue.push(fuel);
        }
        return stops;
    }
};



