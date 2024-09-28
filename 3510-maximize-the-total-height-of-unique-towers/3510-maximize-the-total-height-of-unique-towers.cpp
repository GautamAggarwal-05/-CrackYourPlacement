class Solution {
public:
    long long maximumTotalSum(vector<int>& height) {
        sort(height.begin(),height.end());
        int n=height.size();
        long long sum=0;
        int maxi=INT_MAX;   
        for(int i=n-1;i>=0;i--){
           int value=min(height[i],maxi-1);
           if(value<=0)
            return -1;
           sum+=value;
           maxi=value;
        }
        return sum;
    }

};