class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int mini=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            mini=min(mini,sum);
        }
        return abs(mini)+1;
    }
};