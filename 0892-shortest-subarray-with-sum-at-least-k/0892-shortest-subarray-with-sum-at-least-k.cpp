class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<long long>cumulativesum(n,0);
        int result=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                cumulativesum[j]=nums[j];
            }
            else{
                cumulativesum[j] = cumulativesum[j-1] + nums[j];
            }

            if(cumulativesum[j]>=k){
                result = min(result,j+1);
            }
            while(!dq.empty() && cumulativesum[j]-cumulativesum[dq.front()] >= k){
                result = min(result,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cumulativesum[j] <= cumulativesum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};