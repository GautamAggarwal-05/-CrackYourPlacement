class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0;
        priority_queue<int>maxheap;
        int dist = startFuel;
        int i=0;
        int n = stations.size();
        while(dist<target){
            while(i<n && stations[i][0]<=dist){
                maxheap.push(stations[i][1]);
                i++;
            }
            if(maxheap.empty() && dist<target)
                return -1;
            
            dist+=maxheap.top();
            stops++;
            maxheap.pop();
        }
        return stops;
    }
};