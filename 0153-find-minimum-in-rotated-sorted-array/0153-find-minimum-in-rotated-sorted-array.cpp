class Solution {
public:
    int findMin(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        int e=arr.size()-1;
        if(n==1)
            return arr[0];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>=arr[0] && arr[mid]>=arr[n-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return arr[s];
    }
};