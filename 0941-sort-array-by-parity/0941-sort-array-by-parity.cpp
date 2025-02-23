class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n=arr.size();
        int j=n-1;
        while(j>=0 && arr[j]%2!=0)
            j--;
        int i=0;
        while(i<j){
            if(arr[i]%2!=0 && arr[j]%2==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }else if(arr[j]%2!=0){
                j--;
            }
            else
                i++;
        }

        return arr;
    }
};