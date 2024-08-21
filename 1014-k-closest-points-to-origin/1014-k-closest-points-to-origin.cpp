class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt((x*x)+(y*y));
            pq.push({dist,i});
        }
        while(k-- && !pq.empty()){
            pair<double,int>top = pq.top();
            pq.pop();
            ans.push_back(points[top.second]);
        }
        return ans;
    }
};