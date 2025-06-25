class NumArray {
public:
    int n;
    vector<int>segtree;
    NumArray(vector<int>& nums) {
        n=nums.size();
        segtree=vector<int>(4*n);
        buildSegTree(0,0,n-1,nums);
    }
    
    void buildSegTree(int i,int l,int r,vector<int>&nums){
        if(l==r){
            // cout<<i;
            segtree[i]=nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1,l,mid,nums);
        buildSegTree(2*i+2,mid+1,r,nums);
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }
    void updateSegTree(int i,int l,int r,int index,int val){
        if(l==r){
            segtree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(index<=mid){
            updateSegTree(2*i+1,l,mid,index,val);
        }else{
            updateSegTree(2*i+2,mid+1,r,index,val);
        }
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }
    void update(int index, int val) {
        updateSegTree(0,0,n-1,index,val);   
    }
    int sum(int i,int start,int end,int l,int r){
        if(l>end || r<start)
            return 0;
        else if(start>=l && end<=r)
            return segtree[i];
        else{
            int mid=start+(end-start)/2;
            return sum(2*i+1,start,mid,l,r)+sum(2*i+2,mid+1,end,l,r);
        }
    }
    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */