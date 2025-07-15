class Solution {
public:
    void solve(int i,int n,int target,vector<int>&curr,vector<vector<int>>&ans,vector<int>&arr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i==n){
            if(target==0)
                ans.push_back(curr);
            return;
        }

        for(int idx=i;idx<n;idx++){
            if(idx!=i && arr[idx]==arr[idx-1]) continue;

            if(arr[idx]>target) break;
            curr.push_back(arr[idx]);
            solve(idx+1,n,target-arr[idx],curr,ans,arr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,candidates.size(),target,curr,ans,candidates);
        return ans;
    }
};