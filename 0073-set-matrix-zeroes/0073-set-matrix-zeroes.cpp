class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<pair<int,int>>track;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    track.push_back({i,j});
                }
            }
        }
        for(int i=0;i<track.size();i++){
            int row0=track[i].first;
            int col0=track[i].second;
            for(int j=0;j<col;j++){
                matrix[row0][j]=0;
            }
            for(int k=0;k<row;k++){
                matrix[k][col0]=0;
            }
        }
    }
};