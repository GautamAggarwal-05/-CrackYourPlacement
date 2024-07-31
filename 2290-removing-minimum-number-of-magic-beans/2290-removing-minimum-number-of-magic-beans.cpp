class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long n=beans.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=beans[i];
        }
        long long temp;
        long long ans=9999999999999;
        for(int i=0;i<n;i++){
            temp = sum - (n-i)*beans[i];
            ans=min(ans,temp);
        }
        return ans;
    }
};
