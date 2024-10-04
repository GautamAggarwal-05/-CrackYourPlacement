// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true){
            int row = rand7();
            int col = (rand7()-1)*7;
            int value=row+col;
            if(value<=40){
                return (value-1)%10+1;
            }
        }
    }
};