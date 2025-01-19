class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(auto elem:nums){
            pq.push(elem);
        }
        int n=nums.size();
        for(int i=0;i<n-k;i++){
            pq.pop();
        }
        K=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */