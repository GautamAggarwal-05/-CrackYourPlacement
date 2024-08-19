class Solution {
struct comp{
    bool operator()(pair<char,int>&a,pair<char,int>&b){
        return a.second<b.second;
    }
};
public:
    string reorganizeString(string s) {
        sort(s.begin(),s.end());
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int maxi=INT_MIN;
        for(int i=0;i<26;i++){
            maxi=max(maxi,freq[i]);
        }
        if(maxi > (s.length()+1)/2)
            return "";
        
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                pq.push({i+'a',freq[i]});
            }
        }

        string ans="";
        while(!pq.empty()){
            pair<char,int>  top= pq.top();
            pq.pop();
            if(pq.size()!=1 && !ans.empty() && ans.back() == top.first){
                pair<char,int>stored = top;
                top=pq.top();
                pq.pop();
                pq.push({stored});
            }
            ans+=top.first;
            top.second = top.second-1;
            if(top.second!=0)
                pq.push({top});
            

        }
        return ans;
    }
};