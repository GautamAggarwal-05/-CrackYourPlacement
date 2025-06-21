class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
                    i--;
        }
        cout<<i;
        int j=n-1;

        while(i>=0 &&j>i && nums[i]>=nums[j])
            j--;
        cout<<j;
        if(i>=0)
            swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};