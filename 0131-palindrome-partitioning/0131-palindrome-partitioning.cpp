class Solution {
public:
    bool ispalindrome(string str){
        string temp=str;
        reverse(temp.begin(),temp.end());
        return str==temp;
    }
    void solve(int i,int n,string s,vector<vector<string>>&ans,vector<string>curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        for(int idx=i;idx<n;idx++){
            if(ispalindrome(s.substr(i,idx-i+1))){
                curr.push_back(s.substr(i,idx-i+1));
                solve(idx+1,n,s,ans,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        int n=s.length();
        solve(0,n,s,ans,curr);
        return ans;
    }
};