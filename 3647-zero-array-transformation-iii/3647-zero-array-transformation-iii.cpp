class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int>Aq;//maxheap;
        priority_queue<int,vector<int>,greater<int>>Uq;//minheap;

        int j = 0;
        int used=0;
        int n=nums.size();
        int m=queries.size();
        sort(queries.begin(),queries.end());
        for(int i=0;i<n;i++){
            while(j<m && queries[j][0]==i){
                Aq.push(queries[j][1]);
                j++;
            }
            nums[i]-=Uq.size();
            while(nums[i]>0 && !Aq.empty() && Aq.top()>=i){
                Uq.push(Aq.top());
                Aq.pop();
                nums[i]--;
                used++;
            }
            if(nums[i]>0)
                return -1;
            
            while(!Uq.empty() && i==Uq.top())
                Uq.pop();
        }
        return m-used;
    }
};