class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int k=1;
        int ways=0;
        while(2*n > k*(k-1)){
            int num = n-((k*(k-1))/2);
            int denom = k;
            if(num%k == 0)
                ways++;
            k++;
        }
        return ways;
    }
};