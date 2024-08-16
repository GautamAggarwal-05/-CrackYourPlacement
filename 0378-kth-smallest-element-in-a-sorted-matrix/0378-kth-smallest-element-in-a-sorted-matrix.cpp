class Solution {

public:
    int counter(vector<vector<int>>& matrix, int mid){
        int count = 0;
        int n = matrix.size();
        int row=0;
        int col=n-1;
        while(row<n && col>=0){
            if(matrix[row][col] <=mid){
                count+=col+1;
                row++;
            }
            else{
                col--;
            }
        }
        return count;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(counter(matrix,mid) < k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l;
    }
};