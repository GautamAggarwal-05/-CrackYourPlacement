class MinStack {
public:
    stack<pair<int,int>>st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini,val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        mini = st.empty() ? INT_MAX : st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */