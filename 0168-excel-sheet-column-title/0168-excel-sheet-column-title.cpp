class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num>0)
        { 
            int r=(num-1)%26;
            ans.push_back(char(r+65));
            num=(num-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};