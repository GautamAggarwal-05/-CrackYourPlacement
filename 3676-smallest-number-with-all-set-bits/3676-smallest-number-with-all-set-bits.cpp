class Solution {
public:
    int smallestNumber(int n) {
        int i=1;
        while(true){
            int x=2*i;
            if(x>n){
                return x-1;
            }
            i=2*i;
        }
    }
};