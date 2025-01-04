class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int n=secret.length();
        int i=0,j=0;
        int bullCount=0;
        while(i<n){
            if(secret[i]==guess[j]){
                bullCount++;
            }
            else{
                mp[secret[i]]++;
            }
            i++;
            j++;
        }
        i=0,j=0;
        int cowCount=0;
        while(i<n){
            if(secret[i]!=guess[j]){
                if(mp.find(guess[j])!=mp.end() && mp[guess[j]]>0){
                    cowCount++;
                    mp[guess[j]]--;
                }
            }
            i++;
            j++;
        }
        return to_string(bullCount) + "A" + to_string(cowCount) + "B";
    }
};