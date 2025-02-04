class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9+7;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto num:nums){
            pq.push(num);
        }

        while(k--){
            int top = pq.top();
            pq.pop();

            pq.push(top+1);
        }
        int prod =1 ;
        while(!pq.empty()){
            prod = int((1LL * prod*pq.top()) % mod);
            pq.pop();
        }
        return prod;
    }
};