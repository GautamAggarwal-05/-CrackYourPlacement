#include<limits.h>
class Solution {
private:
    vector<int> next_smaller_elements(vector<int>arr,int n)
    {
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

     vector<int> prev_smaller_element(vector<int>arr,int n)
    {
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
       vector<int>next(n);
       next=next_smaller_elements(heights,n);

       vector<int>prev(n);
       prev=prev_smaller_element(heights,n);
       int area,newarea=INT_MIN;
       for(int i=0; i<n ;i++)
       {
           int l=heights[i];
           if(next[i]==-1)
           {
               next[i]=n;
           }
           int b=next[i]-prev[i]-1;
           
           area=l*b;
           newarea=max(area,newarea);

       }
       return newarea;
    }
};