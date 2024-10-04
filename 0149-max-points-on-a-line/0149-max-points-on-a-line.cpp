class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)
            return 1;
        int result=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int>map;
            int maxi=0;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int x = (points[j][0]-points[i][0]);
                int y = (points[j][1]-points[i][1]);
                double value = atan2(y,x);
                map[value]++;
                maxi=max(maxi,map[value]);
                }
            result=max(result,maxi+1);
        }
        return result;
    }
};