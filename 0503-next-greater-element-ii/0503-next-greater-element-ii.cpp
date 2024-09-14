class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int indx = (i+1)%n;
            while(indx != i && nums[i]>=nums[indx]){
                indx = (indx+1)%n;
            }
            if(indx == i){
                ans.push_back(-1);
            }else{
                ans.push_back(nums[indx]);
            }
        }
        return ans;
    }
};