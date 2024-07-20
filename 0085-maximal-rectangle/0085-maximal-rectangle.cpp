class Solution {
private:

vector<int> leftsmallestElement(vector<int>arr,int n) //left side nextsmallest
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

     vector<int> rightsmallestElement(vector<int>arr,int n) //right side nextlargest
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

    int Histogramarea(vector<int>& heights) {
        int n=heights.size();
       vector<int>next(n);
       next=leftsmallestElement(heights,n);

       vector<int>prev(n);
       prev=rightsmallestElement(heights,n);
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


public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=0,m=0;
        n=mat.size();
        m=mat[0].size();
        vector<int>ans(m,0);
	int newarea=INT_MIN;
	int area=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]!='0')
			{
			ans[j]=ans[j]+(mat[i][j]-'0');
			}
			else
			{
				ans[j]=0;
			}
		}
		area=Histogramarea(ans);
	    newarea=max(area,newarea);

	}
	return newarea;
    }
};