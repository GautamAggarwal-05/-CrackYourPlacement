class Solution {
public:
    void solve(int i,vector<int>curr,vector<vector<int>>&ans){
        if(i==curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int index=i;index<curr.size();index++){
            swap(curr[index],curr[i]);
            solve(i+1,curr,ans);
            swap(curr[index],curr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr=nums;
        solve(0,curr,ans);
        return ans;
    }
};