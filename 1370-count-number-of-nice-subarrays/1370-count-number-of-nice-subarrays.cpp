class Solution {
public:
    int atmostkOdd(vector<int>& nums, int k){
        int window=0,len=0,s=0,e=0;
        int n = nums.size();
        while(e<n){
            if(nums[e]%2!=0){//odd
                window++;
            }
            while(window>k){
                if(nums[s]%2!=0){//odd
                    window--;
                }
                s++;
            }
            len += (e-s+1);
            e++;
        }
        return len; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // atmost of  k odd numbers - atmost of k-1 odd numbers  will give me exactly k odd numers

        return atmostkOdd(nums,k) - atmostkOdd(nums,k-1);
    }
};