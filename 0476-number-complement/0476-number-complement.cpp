class Solution {
public:
    int findComplement(int n) {
        string bits;
        int count=0;
        int ans=0;
        while(n!=0){
            int bit = n%2;
            ans += (pow(2,count)*!bit);
            n=n/2;
            count++;
        }
        return ans;
    }
};