class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=1;
        int n=arr.size();
        int ans=0;
        while(i<n){
            int ascend=0;
            int descend=0;
            while(i<n && arr[i]==arr[i-1])
                i++;
            while(i<n && arr[i]>arr[i-1]){
                ascend++;
                i++;
            }
            while(i<n && arr[i]<arr[i-1]){
                descend++;
                i++;
            }
            if(ascend && descend){
                ans = max(ans,ascend+descend+1);
            }

        }
        return ans;
    }
};