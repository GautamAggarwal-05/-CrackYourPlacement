class Solution {
public:
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j){
            if(s[i]!=s[j]) return false;

            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
             if(s[i]!=s[j]){
                bool first=isPalindrome(s,i+1,j);
                bool second=isPalindrome(s,i,j-1);
                return first || second;
             }

             i++;
             j--;
        }

        return true;
    }
};