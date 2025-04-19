class Solution {
    
public:
    unordered_map<string,int>dp;
    int mod=1e9+7;
    string getkey(int row,vector<int>& prevRow){
        return to_string(row)+"|"+to_string(prevRow[0])+to_string(prevRow[1])+to_string(prevRow[2]);
    }
    int solve(int row, vector<int>prevRow, int n) {
        if(row==n)
            return 1;
        string key=getkey(row,prevRow);
        if(dp.count(key)>0)
            return dp[key];
        int total=0;
        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                for(int c3=0;c3<3;c3++){
                    if (c1 != c2 && c2 != c3 ) { // Horizontal constraint
                        if (row == 0 || (c1 != prevRow[0] && c2 != prevRow[1] && c3 != prevRow[2])) { // Vertical
                            total = (total + solve(row + 1, {c1, c2, c3}, n))%mod;
                        }
                    }
                }
            }
        }
        return dp[key] = total;
    }

    int numOfWays(int n) {
        
        vector<int>arr(3,-1);
        return solve(0,arr, n); 
    }
};
