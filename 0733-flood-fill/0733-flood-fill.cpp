class Solution {
public:
    void dfs(int pixel,int i,int j,int m,int n,vector<vector<int>>& image,int color){
        if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=pixel){
            return ;
        }
        image[i][j]=color;
        dfs(pixel,i+1,j,m,n,image,color);
        dfs(pixel,i-1,j,m,n,image,color);
        dfs(pixel,i,j+1,m,n,image,color);
        dfs(pixel,i,j-1,m,n,image,color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();//row
        int n = image[0].size();//col
        if(image[sr][sc]!=color)
            dfs(image[sr][sc],sr,sc,m,n,image,color);
        return image;
    }
};