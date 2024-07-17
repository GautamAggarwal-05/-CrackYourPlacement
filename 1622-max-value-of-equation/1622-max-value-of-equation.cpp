class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>maxheap;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){

            while((!maxheap.empty()) && points[i][0]-maxheap.top().second > k)
                maxheap.pop();
            
            if(!maxheap.empty()){
                ans = max(ans,points[i][0]+points[i][1]+maxheap.top().first);
            }
            maxheap.push({points[i][1] - points[i][0] , points[i][0]});
        }
        return ans;
    }
};