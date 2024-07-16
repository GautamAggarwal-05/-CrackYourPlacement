class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=INT_MIN;
        int n=cardPoints.size();
        int window = n-k;
        int totalpoints=0;
        for(int i=0;i<n;i++){
            totalpoints +=cardPoints[i];
        }
        int counter = 0;
        int start=0;
        int end=0;
        int sum=0;
        while(counter<=k ){
            while(end<n && end - start < window){
                sum+=cardPoints[end];
                end++;
            }
            ans = max(ans,totalpoints-sum);
            sum-=cardPoints[start];
            start++;
            counter++;
        }
        return ans;
    }
};