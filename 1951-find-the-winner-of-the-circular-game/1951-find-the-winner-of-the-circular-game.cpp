class Solution {
public:
    int findWinnerIndex(int n,int k){
        if(n==1)//only one player left means index is 0;
            return 0;
        
        int indx = findWinnerIndex(n-1,k);
        indx = (indx+k)%n;//original index of original array if element not got deleted;
        return indx;
    }
    int findTheWinner(int n, int k) {
        return findWinnerIndex(n,k)+1;
    }
};