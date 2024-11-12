class Solution {
public:
    int findIndex(int low,int high,int target,vector<vector<int>>& arr){
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid][0]<=target){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        vector<int>storemaxi(n,0);
        int maxi=INT_MIN;
        storemaxi[0]=items[0][1];
        for(int i=1;i<n;i++){
            storemaxi[i] = max(storemaxi[i-1],items[i][1]);
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int indx = findIndex(0,n-1,queries[i],items);
            if(indx==-1){
                ans.push_back(0);
                continue;
            }
            ans.push_back(storemaxi[indx]);
        }
        return ans;
    }
};