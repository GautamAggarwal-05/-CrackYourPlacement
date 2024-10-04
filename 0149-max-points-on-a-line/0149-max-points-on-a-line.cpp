class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)
            return 1;
        int maxi=0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x = (points[i][0]-points[j][0]);
                int y = (points[i][1]-points[j][1]);
                int count=2;
                for(int k=0;k<points.size();k++){
                    if(k!=i && k!=j){
                        int x_=  (points[i][0] - points[k][0]);
                        int y_ = (points[i][1] - points[k][1]);
                        if(x*y_ == y*x_)
                            count++;
                    }
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};