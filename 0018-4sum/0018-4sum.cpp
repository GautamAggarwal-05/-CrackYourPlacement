class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int a=0,b=0,c=0,d=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(a=0;a < n-3;a++){
            if(a>0 && nums[a] == nums[a-1])
                continue;
            for(d=n-1;d>=3;d--){
                if(d<n-1 && nums[d]==nums[d+1]){
                    continue;
                }
                b=a+1;
                c=d-1;
                while(b<c){
                    long long value =(long long) nums[a]+nums[b]+nums[c]+nums[d];
                    if(value>target){
                        c--;
                    }
                    else if(value<target){
                        b++;
                    }
                    else{
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        b++;
                        while(b<c && nums[b-1] == nums[b])
                        {
                            b++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};