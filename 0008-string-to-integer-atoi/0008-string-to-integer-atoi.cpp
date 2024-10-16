class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        while(i<n && s[i]=='0'){
            i++;
        }
        int num=0;
        while(i<n){
            if(s[i]<'0' || s[i]>'9')
                break;
            int n=s[i]-'0';
            if (num > (INT_MAX - n) / 10) {
                // If overflow happens, return the maximum or minimum value
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + n;
            i++;
        }
        return num*sign;
    }
};