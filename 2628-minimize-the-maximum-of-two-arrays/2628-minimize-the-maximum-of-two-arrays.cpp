class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low=1;
        long long high = 10e9;
        int ans=0;
        long long l = ((1LL*divisor1*divisor2))/gcd(divisor1,divisor2); // lcm;
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long a = mid - (mid/divisor1); // no of elem before mid which are not divisible by divisor 1 go in arr1;
            long long b = mid - (mid/divisor2); // no of elem before mid which are not divisible by divisor 2 go in arr2;
            
            long long c = mid - (mid/divisor1) - (mid/divisor2) + (mid/l); // no of elem which are both     not divisible by d1 and d2 so they now we substracted some elem 2 times  so we added that many number of common elements go in both arr1 and arr2

    // mid=15 d1=3 d2=5 15/3=5 elem before 15 in arr1 (3,6,9,12,15)
    // 15/5=3 elem in arr2 (5,10,15) we can see 15 2 times means in c we substracted that number(15) 1  time extra so we added that number 1 time (15/lcm(3,5))=1
            if(a >= uniqueCnt1 && b >= uniqueCnt2 && (a+b-c) >= uniqueCnt1+uniqueCnt2){
                ans=mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};