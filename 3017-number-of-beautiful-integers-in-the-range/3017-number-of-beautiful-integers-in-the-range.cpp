class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int ans=0;
        if(high>1e8)
            high = 1e8;
        for(int i=low;i<=high;i++){
            int num = i;
            if(num%k==0){
                int even=0;
                int odd=0;
                while(num!=0){
                    int d=num%10;
                    if (d%2==0)
                        even++;
                    else 
                        odd++;
                    num=num/10;
                }
                if(even!=0 && odd!=0 && even==odd){
                    ans++;
                }

            }
        }
        return ans;
    }
};