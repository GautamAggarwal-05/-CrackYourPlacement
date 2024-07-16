class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        int count=0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                nums[j++]=nums[i++];
            }
            else
            {
                count++;
                i++;
            }
        }
        while(count--)
        {
            nums[j++]=0;
        }
    }
};