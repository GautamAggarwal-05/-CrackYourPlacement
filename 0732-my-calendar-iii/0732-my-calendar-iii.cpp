class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
            mp[start]++;
            mp[end]--;
        
        int sum=0;
        int k=1;
        for(auto elem : mp){
            sum += elem.second;
            k=max(k,sum);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */