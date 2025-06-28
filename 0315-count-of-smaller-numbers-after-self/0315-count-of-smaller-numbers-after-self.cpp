class Solution {
public:
    void updateBIT(int i,int val,int n,vector<int>&fentree){
        while(i<n){
            fentree[i]+=val;
            i=i+(i&(-i));
        }
    }
    int queryBIT(int i,vector<int>&fentree){
        int s=0;
        while(i>0){
            s+=fentree[i];
            i=i-(i&(-i));
        }
        return s;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int>fentree(n+1,0);
        sort(arr.begin(),arr.end());
        vector<int>result(n);
        for(int i=0;i<n;i++){
            updateBIT(arr[i].second+1,1,n+1,fentree);
            int x=queryBIT(n,fentree) - queryBIT(arr[i].second+1,fentree);
            result[arr[i].second]=x;
        }
        return result;
    }
};