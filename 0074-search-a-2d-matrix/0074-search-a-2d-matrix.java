class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // search which row and then in that row search the target;
        int row = matrix.length;
        int col = matrix[0].length;

        int low = 0;
        int high = row-1;
        int rowindx=-1;
        while(low<=high){
            int mid = (high+low)/2;

            if(matrix[mid][col-1]>=target){
                rowindx=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        System.out.println(rowindx+" ");
        if(rowindx == -1)
            return false;

        low = 0;
        high = col-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[rowindx][mid] == target){
                return true;
            }else if(matrix[rowindx][mid] < target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
}