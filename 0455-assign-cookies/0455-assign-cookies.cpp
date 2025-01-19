class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int bacha=0;
        while(i<g.size() && j<s.size()){
            if(s[j]-g[i]>=0){
                i++;
                j++;
                bacha++;
            }
            else{
                j++;
            }
            
        }
        return bacha;
    }
};