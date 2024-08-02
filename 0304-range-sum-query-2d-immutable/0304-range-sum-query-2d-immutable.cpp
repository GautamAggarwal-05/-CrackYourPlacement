class NumMatrix {
public:
    vector<vector<int>>matrix1;
    NumMatrix(vector<vector<int>>& matrix) {
        matrix1 = matrix;
        int n=matrix1.size();
        int m=matrix1[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix1[i][j] = matrix1[i][j] + matrix1[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            // cout<<matrix1[i][col2]<<" "<<matrix1[i][col1-1]<<endl;
            if(col1-1>=0)
                sum+=(matrix1[i][col2]-matrix1[i][col1-1]);
            else
                sum+=matrix1[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */