class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int>curr = ans.back();
                if(intervals[i][0]<=curr[1]){
                  if(intervals[i][1]>=curr[1]){
                    ans.pop_back();
                    ans.push_back({curr[0],intervals[i][1]});
                  }
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};