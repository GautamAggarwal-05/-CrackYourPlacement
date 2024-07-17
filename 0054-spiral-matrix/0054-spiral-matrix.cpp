class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        long long totalelem=0;
        int rowIndx=0;
        int colIndx=m-1;
        int revRow=n-1;
        int revCol=0;
        while(totalelem < m*n){
           
            for(int i=rowIndx; totalelem < m*n && i<=colIndx ;i++){
                ans.push_back(matrix[rowIndx][i]);
                totalelem++;
            }
             
            rowIndx++;
            
            for(int i=rowIndx;totalelem < m*n && i<=revRow;i++){
                ans.push_back(matrix[i][colIndx]);
                totalelem++;
            }
            
            colIndx--;

            for(int i = colIndx;totalelem < m*n && i>=revCol;i--){
                ans.push_back(matrix[revRow][i]);
                totalelem++;
            }
            
            revRow--;
            for(int i=revRow;totalelem < m*n && i>=rowIndx;i--){
                ans.push_back(matrix[i][revCol]);
                totalelem++;
            }
             
            revCol++;
        }
        return ans;
    }
};