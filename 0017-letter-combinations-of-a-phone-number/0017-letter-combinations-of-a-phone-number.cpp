class Solution {
    string mapping[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void solve(int i,int n, string digits,string temp,vector<string>&ans){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        string str = mapping[digits[i]-'0'];
        for(int j=0;j<str.length();j++){
            temp.push_back(str[j]);
            solve(i+1,n,digits,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
        if(n==0)
            return {};
        string temp;
        vector<string>ans;
        solve(0,n,digits,temp,ans);
        return ans;
    }
};