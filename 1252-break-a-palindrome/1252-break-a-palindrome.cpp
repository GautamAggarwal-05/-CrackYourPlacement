class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1) return "";
        int m = n%2==0?n:n/2;
        int i=0;
        for(i=0;i<m;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                break;
            }
        }
        if(i==m)
            palindrome[n-1]='b';
        
        return palindrome;
    }
};