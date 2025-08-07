class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a=str1.length();
        int b=str2.length();
        if(str1+str2!=str2+str1)
            return "";
        int common=gcd(a,b);
        string b1=str2.substr(0,common);
        for(int i=0;i<a;i+=common){
            string a1=str1.substr(i,common);
            if(a1!=b1)
                return "";
        }
        return str1.substr(0,common);
    }
};