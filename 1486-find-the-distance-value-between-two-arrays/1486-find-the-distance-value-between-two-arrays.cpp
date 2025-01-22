class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        int ans=0;
        for(auto elem:arr1){
            int left_limit = elem - d;
            int right_limit = elem + d;
            int low = 0;
            int n = arr2.size();
            int high = n-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(arr2[mid]>=left_limit && arr2[mid]<=right_limit){
                    ans++;
                    break;
                }
                else if(arr2[mid]<left_limit){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return arr1.size() - ans;
    }
};