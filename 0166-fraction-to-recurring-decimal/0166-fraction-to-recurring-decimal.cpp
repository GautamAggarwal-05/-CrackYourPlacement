class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num==0)
            return "0";
        int count=0;
        if(num<0)
            count++;
        if(den<0)
            count++;
        num=abs(num);
        den=abs(den);
        long long q=num/den;
        long long rem=num%den;
        string ans="";
        ans+= to_string(q);
        if(rem==0){
            if(count==1)
                return "-"+ans;
            else
                return ans;
        }
        ans+=".";
        unordered_map<int,int>mp;
        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                int len=mp[rem];
                string s1=ans.substr(0,len);//repeat sai phele kai number
                string s2 = ans.substr(len);//repeat lai baad kai number 
                ans = s1+"("+s2+")";
                break;// repeating value found out
            }
            else{
                mp[rem]=ans.size(); //storing remainder and the index of the quetionent so later we can find out where the repeating thing starts from.
                rem=rem*10;
                q=rem/den;
                rem=rem%den;
                ans+=to_string(q);
            }
        }
        if(count==1)
            return '-'+ans;
        return ans;
    }

};