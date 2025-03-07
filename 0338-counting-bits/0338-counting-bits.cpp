class Solution {
public:
   // if the number is odd - 1bit count is i/2+1 1bits
   //and if number is even - 1 bit count is i/2 1bits;
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2!=0)
                ans[i] = (ans[i/2]+1);
            else
                ans[i] = (ans[i/2]);
        }
        return ans;
    }
};