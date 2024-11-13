class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long m=n-1;
        long long total = (m*(m+1))/2;
        long long lowerpair=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]<lower){
                lowerpair+= (j-i);
                i++;
            }
            else
                j--;
        }
        i=0,j=n-1;
        long long upperpair=0;
        while(i<j){
            if(nums[i]+nums[j]>upper){
                upperpair+= (j-i);
                j--;
            }
            else
                i++;
        }

        return total - lowerpair - upperpair;
    }
};