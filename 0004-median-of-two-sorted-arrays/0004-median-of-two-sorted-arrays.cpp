class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i] <=nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            merge.push_back(nums1[i]);
                i++;
        }
        while(j<m){
            merge.push_back(nums2[j]);
                j++;
        }
        int k=merge.size();
        if(k%2!=0){
            return double(merge[k/2]);
        }
        else{
            int mid=k/2;
            return double(merge[mid]+merge[mid -1])/2;
        }
    }
};