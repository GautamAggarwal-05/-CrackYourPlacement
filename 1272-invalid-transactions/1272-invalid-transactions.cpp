class Solution {
public:
    //1 . Method to split string
    vector<string> extract(string s){
        string t="";
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==','){
                v.push_back(t);
                t="";
            }else
                t+=s[i];    
        }
        v.emplace_back(t);
        return v;
    }
    
    // 2. This function checks the second condition.
    bool check(string s,string time,string city,map<string,vector<string>>mp){
        for(auto &x:mp[s]){
            vector<string> tmp = extract(x);
            int val1 = stoi(tmp[1]);
            int val2 = stoi(time);
            if(tmp[3]!=city and abs(val2-val1)<=60)
                return true;
        }
        return false;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
      
        map<string,vector<string>> mp;/* stores mapping of name to transaction*/
        
        int n = transactions.size();
        
        vector<vector<string>> v(n,vector<string>(4)); /*ith vector<string> stores info about ith transaction*/
        int c = 0;
        
        for(auto &x:transactions){
            vector<string> tmp=extract(x);
            v[c++] = tmp;
            mp[tmp[0]].push_back(x);
        }
        
        for(int i=0;i<n;i++){
            
             if(stoi(v[i][2])>1000){
                // check for first condition
                 res.push_back(transactions[i]);
             }else{
                 // checks for second condition.
                 if(check(v[i][0],v[i][1],v[i][3],mp)){
                     res.push_back(transactions[i]);
                 }
             }
            
        }
        return res;
    }
};