class Solution {
public:
    string getPermutation(int n, int k) {
        string arr;
        for(int i=1;i<=n;i++){
            arr+=to_string(i);
        }
        k--;
        while(k--){
            next_permutation(arr.begin(),arr.end());
        }
        return arr;
    }
};