class SegmentTree2d{

    vector<vector<int>>segtree;
    vector<vector<int>>mat;
    int m,n;
    public:
    SegmentTree2d(vector<vector<int>>&matrix){
         m=matrix.size();
         n=matrix[0].size();
        mat=matrix;
        segtree.assign(4*m,vector<int>(4*n,0));
        buildX(0,0,m-1);
    }
    
    void buildY(int nodeX,int lx,int rx,int nodeY,int ly,int ry){
        if(ly==ry){
            if(lx==rx){
                segtree[nodeX][nodeY]=mat[lx][ly];
            }else{
                segtree[nodeX][nodeY]=segtree[2*nodeX+1][nodeY]+
                segtree[2*nodeX+2][nodeY];
            }
        }
        else{
        int midy=(ly+ry)/2;
        buildY(nodeX,lx,rx,2*nodeY+1,ly,midy);
        buildY(nodeX,lx,rx,2*nodeY+2,midy+1,ry);
        segtree[nodeX][nodeY]=segtree[nodeX][2*nodeY+1]+segtree[nodeX][2*nodeY+2];
        }
    }
    void buildX(int nodeX,int lx,int rx){
        if(lx!=rx){
            int midx=(lx+rx)/2;
            buildX(2*nodeX+1,lx,midx);
            buildX(2*nodeX+2,midx+1,rx);
        }
        buildY(nodeX,lx,rx,0,0,n-1);
    }

    int queryY(int nodeX, int nodeY, int ly, int ry, int qly, int qry) {
        if (qry < ly || ry < qly) return 0;
        if (qly <= ly && ry <= qry) return segtree[nodeX][nodeY];
        int my = (ly + ry) / 2;
        return queryY(nodeX, 2 * nodeY + 1, ly, my, qly, qry) +
               queryY(nodeX, 2 * nodeY + 2, my + 1, ry, qly, qry);
    }
    int queryX(int nodeX,int lx,int rx,int qlx,int qrx,int qly,int qry){
        if(qrx < lx || qlx>rx)
            return 0;
        if(qlx<=lx && rx<=qrx)
            return queryY(nodeX,0,0,n-1,qly,qry);
        int mx = (lx + rx) / 2;
        return queryX(2 * nodeX + 1, lx, mx, qlx, qrx, qly, qry) +
               queryX(2 * nodeX + 2, mx + 1, rx, qlx, qrx, qly, qry);
    }
    int query(int row1,int col1,int row2,int col2){
        return queryX(0,0,m-1,row1,row2,col1,col2);
    }
};

class NumMatrix {
public:
    SegmentTree2d *segtree;
    NumMatrix(vector<vector<int>>& matrix) {
        segtree = new SegmentTree2d(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return segtree->query(row1,col1,row2,col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */