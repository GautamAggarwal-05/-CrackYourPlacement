class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber!=0){
            int rem = (columnNumber-1)%26;
            ans = char(rem+65)+ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
    }
};