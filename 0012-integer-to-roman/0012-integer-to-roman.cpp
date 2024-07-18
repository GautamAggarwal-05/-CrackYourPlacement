class Solution {
public:
    string intToRoman(int num) {
    string ans="";
    int count=0;
  
        while(num >= 1000){
            num-=1000;
            ans.push_back('M');
        }
            if(num/900){
                ans.push_back('C');
                ans.push_back('M');
                num-=900;
            }
                while(num>=500){
                    num-=500;
                    ans.push_back('D');
                }
                if(num/400){
                    ans.append("CD");
                    num-=400;
                }
                while(num>=100){
                    num-=100;
                    ans.push_back('C');
                }
            if(num/90){
                num-=90;
                ans.push_back('X');
                ans.push_back('C');
            }
            while(num>=50){
                num-=50;
                ans.push_back('L');
            }
            if(num/40){
                num-=40;
                ans.push_back('X');
                ans.push_back('L');
            }
            while(num>=10){
                num-=10;
                ans.push_back('X');
            }
            if(num/9){
                num-=9;
                ans.push_back('I');
                ans.push_back('X');
            }
            if(num>=5){
                num-=5;
                ans.push_back('V');
            }
            if(num/4){
                num-=4;
                ans.append("IV");
            }
            while(num!=0){
                num-=1;
                ans.push_back('I');
            }
            
        
    return ans;
    }
};