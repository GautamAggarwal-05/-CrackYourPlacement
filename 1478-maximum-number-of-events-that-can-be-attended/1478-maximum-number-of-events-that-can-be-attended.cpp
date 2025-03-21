#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, std::greater<int>> minHeap; // store end day here
        int i = 0, n = events.size(), count = 0, day = 1;

        // Step 2: Process events day by day
        while (i < n || !minHeap.empty()) {
            // Add all events that start on or before `day`
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]); // Push the event's end day
                i++;
            }

            // Remove events that have expired (end day < current day)
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // If there is an available event, attend it
            if (!minHeap.empty()) {
                minHeap.pop(); // Attend the event that ends the earliest
                count++;       // Increase the count of attended events
            }

            // Move to the next day
            day++;
        }

        return count;
    }
};
