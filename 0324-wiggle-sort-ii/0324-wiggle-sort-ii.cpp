class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> duplicate = nums;
        sort(duplicate.begin(), duplicate.end());
        
        int n = nums.size();
        int mid = (n + 1) / 2;
        int i = mid - 1;
        int j = n - 1; 
        int k = 0;   
        
        while (k < n) {
            // Place from the smaller half for even indices
            if (k % 2 == 0) {
                nums[k++] = duplicate[i--];
            } 
            // Place from the larger half for odd indices
            else {
                nums[k++] = duplicate[j--];
            }
        }
    }
};
