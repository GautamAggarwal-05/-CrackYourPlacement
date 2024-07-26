class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        for(int i=0;i<s.length();i++){
            if(!s1.empty() && s[i]=='#'){
                s1.pop();
            }else if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        string str1="";
        while(!s1.empty()){
            str1 = s1.top()+str1;
            s1.pop();
        }

        for(int i=0;i<t.length();i++){
            if(!s1.empty() && t[i]=='#'){
                s1.pop();
            }else if(t[i]!='#'){
                s1.push(t[i]);
            }
        }
        string str2="";
        while(!s1.empty()){
            str2 = s1.top()+str2;
            s1.pop();
        }

        return str1 == str2;
    }
};