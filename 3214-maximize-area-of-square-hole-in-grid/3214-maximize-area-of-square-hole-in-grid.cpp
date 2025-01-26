class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxih=1;
        int maxiv=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int count=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]+1 == hBars[i]){
                count++;
            }
            else{
                count=1;
            }
            maxih = max(maxih,count);
        }
        count=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]+1 == vBars[i]){
                count++;
            }
            else{
                count=1;
            }
            maxiv = max(maxiv,count);
        }
        cout<<maxiv;
        int side = min(maxih,maxiv)+1;
        return side * side;
    }
};