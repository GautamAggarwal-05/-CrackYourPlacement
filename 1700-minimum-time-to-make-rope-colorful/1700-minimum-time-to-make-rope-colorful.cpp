class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int i=0,j=1;
        int n = time.size();
        int ans=0;
        while(j<n){
            if(colors[i]==colors[j]){
                if(time[i]<time[j]){
                    ans+=time[i];
                    i=j;
                    j++;
                }
                else{
                    ans+=time[j];
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
};