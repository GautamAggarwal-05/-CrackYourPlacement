class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int result=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i]-1)>0)
                continue;
            int count=1;
            int value=nums[i]+1;
            while(st.count(value)>0){
                value+=1;
                count++;
            }
            result = max(result,count);
        }
        return result;
    }
};