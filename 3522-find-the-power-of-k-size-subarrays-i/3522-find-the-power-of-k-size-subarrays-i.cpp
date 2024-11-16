class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int s=0;
        int e=1;
        int n = nums.size();
        if(n==1)
            return {nums[0]};
        vector<int>result;
        while(e<n){
            int ans=0;
            while(e-s+1<=k){
                for(int i=s+1;i<=e;i++){
                    if(nums[i-1]+1 != nums[i]){
                        ans=-1;
                        break;
                    }
                }
                e++;
            }
            if(ans==-1){
                result.push_back(ans);
            }
            else{
                result.push_back(nums[e-1]);
            }
            s++;
        }
        return result;
    }
};