class Solution {
public:
    bool solve(int i,vector<int>& arr,vector<bool>& visited){
        if(i<0 || i>arr.size()-1)
            return false;
        
        if(arr[i]==0)
            return true;
        if(visited[i])
            return false;
        visited[i]=true;
        return solve(i+arr[i],arr,visited) || solve(i-arr[i],arr,visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>visited(n+1,false);
        return solve(start,arr,visited);
    }
};