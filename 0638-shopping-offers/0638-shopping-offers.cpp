class Solution {
public:
    map<vector<int>,int>map;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(map.count(needs)!=0){
            return map[needs];
        }
        int ans=0;
        int n=price.size();
        for(int i=0;i<n;i++){
            ans +=(price[i]*needs[i]);
        }

        for(int i=0;i<special.size();i++){
            bool isvalidoffer=true;
            for(int j=0;j<n;j++){
                if(special[i][j] > needs[j]){
                    isvalidoffer=false;
                    break;
                }
            }

            if(isvalidoffer){
                for(int j=0;j<needs.size();j++){
                    needs[j] -= special[i][j];
                }
                int ans1 = special[i].back()+shoppingOffers(price,special,needs);
                ans=min(ans,ans1);
                for(int j=0;j<needs.size();j++){//backtrack the need 
                    needs[j] += special[i][j];
                }
            }
        }
        return map[needs] = ans;
    }
};