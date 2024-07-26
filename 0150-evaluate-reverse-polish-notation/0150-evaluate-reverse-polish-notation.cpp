class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++)
        {
            string ch=tokens[i];
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/")
            {
                s.push(stoi(ch));
            }
            else
            {
                 int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                if(ch=="+")
                {
                   
                    s.push(b+a);
                }
                else if(ch=="-")
                {
                    s.push(b-a);
                }
                if(ch=="*")
                {
                    s.push(b*a);
                }
                if(ch=="/")
                {
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};