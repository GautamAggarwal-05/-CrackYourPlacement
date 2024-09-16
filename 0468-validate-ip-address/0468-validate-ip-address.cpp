class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = queryIP.length();
        int dotCount=0;
        int colon=0;
        for(int i=0;i<n;i++){
            if(queryIP[i]=='.'){
                dotCount++;
            }
            else if(queryIP[i]==':'){
                colon++;
            }
        }
        if(colon!=0 && dotCount!=0)
            return "Neither";
        if(n==0 || queryIP[n-1]=='.' || queryIP[n-1]==':' )
            return "Neither";
        if(dotCount==3){
            //IPV4
            for(int i=0;i<n;i++){
                string digit="";
                while(i<n && queryIP[i]!='.'){
                    digit += queryIP[i];
                    i++;
                }
                if (digit.empty() || digit.size() > 3 || (digit.size() > 1 && digit[0] == '0'))
                    return "Neither";
                for(int j=0;j<digit.size();j++){
                    if(isalpha(digit[j]))
                        return "Neither";
                }
                int num = stoi(digit);
                if(num<0 || num>255){
                    return "Neither";
                }
                
            }
            return "IPv4";
        }
        else if(colon == 7){
            //IPV6
            for(int i=0;i<n;i++){
                string digit="";
                while(i<n && queryIP[i]!=':'){
                    digit += queryIP[i];
                    i++;
                }
                cout<<digit<<endl;
                if(digit=="")
                    return "Neither";
                if(digit.length()>4 || digit.length()<=0)
                    return "Neither";
                for(int j=0;j<digit.length();j++){
                    if(toupper(digit[j])>'F')
                        return "Neither";
                }
                
            }
            return "IPv6";
        }
        return "Neither";
    }
};