class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>s;
        int n=temp.size();
        vector<int>result(n);
        for(int i=n-1;i>=0;i--)
        {
          while(!s.empty() && temp[i]>=temp[s.top()])
          {
              s.pop();
          }
          if(s.empty())
              result[i]=0;
          else
          result[i]=s.top()-i;
          s.push(i);
        }
        return result;
    }
};