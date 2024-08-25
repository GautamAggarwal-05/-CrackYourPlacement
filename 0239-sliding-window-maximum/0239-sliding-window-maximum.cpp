class Solution {
public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size(),i;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        for( i=0;i<k;i++)
            pq.push({nums[i],i});

        res.push_back(pq.top().first);

        for(;i<n;i++)
        {
            while(!pq.empty() && pq.top().second<=i-k){
             pq.pop();

            }
            pq.push({nums[i],i});
            res.push_back(pq.top().first);
        }
        return res;
    }
};