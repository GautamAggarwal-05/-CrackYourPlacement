class Solution {
    double solve(double x,int n){
        if(n==0){
            return 1;
        }
        if(n==1)
            return x;
        double ans=1.0;
        if((n & (n - 1)) == 0){// power of 2
            ans = solve(x,n/2);
            return ans*ans;
        }else{
            return x * solve(x,n-1);
        }
    }
    public double myPow(double x, int n) {
        // double ans=1.0;
        // int m=n;
        // if(n<0)
        //     n = n*-1;
        // for(int i=0;i<n;i++){
        //     ans = ans * x;
        // }
        // if(m<0)
        //     return 1/ans;
        // return ans;
        int m = n;
        if(n<0)
            n=n*-1;
        double res = solve(x,n);
        if(m<0)
            return 1/res;
        return res;

    }
}