class Solution {
    
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int indx=n-1;indx>=0;indx--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                 if (buy) {
                 // jab buy karre hai then add negative price and agar ek baar buy kiya to phele sell hi karna padega dobara buy allowed nhi hai
                    int include = (-1) * prices[indx] + next[0];
                    int exclude = 0 + next[1];
                    curr[buy] = max(include, exclude); // maximizing the profit
                } 
                else {
                    // jab sell karna hai then add the positive price and again we are allowed to buy stock
                    int include = prices[indx] + next[1];
                    int exclude = next[0];
                    curr[buy] = max(include, exclude);
                    }
            }
            next=curr;
        }
        return next[1];
    }
};
