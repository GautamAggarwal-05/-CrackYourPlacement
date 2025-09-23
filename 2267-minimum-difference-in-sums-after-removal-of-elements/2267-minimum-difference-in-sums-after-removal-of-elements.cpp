class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;
        vector<long long>left(m);
        vector<long long>right(m);
        priority_queue<int>maxheap;
        priority_queue<int,vector<int>,greater<int>>minheap;
        //left sum
        left[0]=nums[0];
        maxheap.push(nums[0]);
        for(int i=1;i<=2*n-1;i++){
            long long x = left[i-1]+nums[i];
            maxheap.push(nums[i]);
            if(maxheap.size()>n){
                x = x-maxheap.top();
                maxheap.pop();
            }
            left[i]=x;
        }

        //right sum;
        right[3*n-1]=nums[3*n-1];
        minheap.push(nums[m-1]);
        for(int i=3*n-2; i>=n;i--){
            long long x = right[i+1] + nums[i];
            minheap.push(nums[i]);
            if(minheap.size()>n){
                x = x-minheap.top();
                minheap.pop();
            }
            right[i]=x;
        }

        long long res=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            res = min(res,left[i]-right[i+1]);
        }

        return res;
    }
};