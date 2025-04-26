class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int>maxheap;
        int currpos=0;
        int remainfuel=startFuel;
        stations.push_back({target,0});
        int count=0;
        for(int i=0;i<=n;i++){
            int fuel=stations[i][1];
            int pos=stations[i][0];
            while(remainfuel+currpos<pos){
                if(maxheap.empty())
                    return -1;
                remainfuel+=maxheap.top();
                maxheap.pop();
                count++;
            }
            remainfuel -= (pos-currpos);
            currpos=pos;
            maxheap.push(fuel);
        }
        return count;
    }
};