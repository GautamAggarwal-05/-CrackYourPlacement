class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int count=0;
        int i=0,j=0;
        while(count < m*n){
            ans.push_back(mat[i][j]);
            if((i+j)%2 == 0){
                if(i-1>=0 && j+1<m){
                    i--;
                    j++;
                }
                else if(j+1<m)
                    j++;
                else
                    i++;
            }
            else{
                if(j-1>=0 && i+1<n){
                    i++;
                    j--;
                } 
                else if(i+1<n){
                    i++;
                }
                else{
                    j++;
                }
            }
            count++;
        }
        return ans;
    }
};