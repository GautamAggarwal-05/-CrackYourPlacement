class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currtank=0;
        int totaltank=0;
        int n=gas.size();
        int start=0;
        //  find a point from where the curr tank will always be positive beacuse if it will always bw positive means it will reach to its destination and after loops end check if we were able to compensate all thise negative generated values with all the positive values we got after start if yes then the start index is correct else we did not find any start index;
        for(int i=0;i<n;i++){
            totaltank += gas[i]-cost[i];
            currtank += gas[i]-cost[i];
            if(currtank<0){
                currtank=0;
                start=i+1;
            }
        }

        return totaltank>=0 ? start : -1;
    }
};