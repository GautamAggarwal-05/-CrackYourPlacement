class StockSpanner {
public:
    stack<pair<int,int>>s1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(!s1.empty() && s1.top().first<=price){
            count +=s1.top().second;
            s1.pop();
        }
        s1.push({price,count});
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */