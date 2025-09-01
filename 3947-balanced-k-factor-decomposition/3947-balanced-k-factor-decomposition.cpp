class Solution {
public:
    vector<int>best;
    int bestdiff = INT_MAX;
    void solve(int n,int k,vector<int>curr){
        if(k==0){
            if(n==1){
                int maxi=*max_element(curr.begin(),curr.end());
                int mini=*min_element(curr.begin(),curr.end());
                if(maxi-mini < bestdiff){
                    bestdiff = maxi-mini;
                    best=curr;
                }
            }
            return; 
        }

        for(int i=1;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                solve(n/i,k-1,curr);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int>curr;
        solve(n,k,curr);
        return best;
    }
};