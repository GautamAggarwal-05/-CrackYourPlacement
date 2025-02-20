class Solution {
public:
    vector<int>left_arr;
    vector<int>right_arr;
    void NSL(vector<int> arr){
        int n = arr.size();
        left_arr.resize(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()] > arr[i]){
                st.pop();
            }
            left_arr[i] = st.top();
            st.push(i);
        }
    }
    void NSR(vector<int> arr){
        int n = arr.size();
        right_arr.resize(n);
        stack<int>st;
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && arr[st.top()] >= arr[i]){
                st.pop();
            }
            right_arr[i] = st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        NSL(arr);
        NSR(arr);
        long long sum=0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            int left = i-left_arr[i];
            int right = abs(right_arr[i]-i);
            sum = (sum + (1LL * arr[i]*left*right))%mod;
        }
        return static_cast<int>(sum);
    }
};