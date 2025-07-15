class Solution {
public:
    void solve(int i,int n,int target,vector<int>&curr,vector<vector<int>>&ans,vector<int>&arr){
        if(i==n){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(arr[i]<=target){
            curr.push_back(arr[i]);
            solve(i,n,target-arr[i],curr,ans,arr);
            curr.pop_back();
        }

        solve(i+1,n,target,curr,ans,arr);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n = arr.size();
        solve(0,n,target,curr,ans,arr);
        return ans;
    }
};