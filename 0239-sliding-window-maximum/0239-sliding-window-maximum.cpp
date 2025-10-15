class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        int i=0;
        for(;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(pq.top().first);
        while(i<n){
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({nums[i],i});
            auto top=pq.top();
            int val=top.first;
            ans.push_back(val);
            i++;
        }
        return ans;
    }
};