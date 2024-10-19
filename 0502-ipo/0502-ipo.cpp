class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>maxheap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minheap;

        for(int i=0;i<capital.size();i++){
            minheap.push({capital[i],profits[i]});
        }

        while(k>0){

            while(!minheap.empty() && minheap.top().first <= w){
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if(maxheap.empty()){
                return w;
            }
            w+=maxheap.top();
            maxheap.pop();
            k--;
        }
        return w;
    }
};