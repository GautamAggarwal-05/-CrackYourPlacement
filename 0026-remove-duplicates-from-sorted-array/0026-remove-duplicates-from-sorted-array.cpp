class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int k=0;
        int n = nums.size();
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[k]=nums[i];
                k++;
            }
            i++;
        }
        nums[k++] = nums[i];
        return k;
    }
};