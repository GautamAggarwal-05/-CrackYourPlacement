class Solution {
public:
    string addBinary(string a, string b) {
        int sum=0;
        int digit=0;
        int carry=0;
        string result="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
       
        int i = 0;
        while (i < a.length() || i < b.length() || carry != 0) {
           
            sum = carry;
            if (i < a.length())
             sum += (a[i] - '0');
            if (i < b.length())
             sum += (b[i] - '0');

            carry = sum / 2;
            sum %= 2;
            result += (sum + '0');
            i++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};