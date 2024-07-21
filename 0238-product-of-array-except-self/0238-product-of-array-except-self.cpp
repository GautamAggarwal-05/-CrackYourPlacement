class Solution {
public:
    int product(vector<int>& nums)
    {
        int i,val=1;
        for(i=0;i<nums.size();i++)
        {
            val*=nums[i];
        }
        return val;

    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int i=0,index;
        int val=product(nums);
        vector<int>ans;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                vector<int>temp=nums;
                temp.erase(temp.begin()+i);
                int p=product(temp);
                ans.push_back(p);
            }
            else
            {
                
                ans.push_back(val/nums[i]);
            }
        }
        return ans;
    }
};