class Solution {
public:
    int countOfSubstrings(string word, int k) {
        vector<string>v;
        for(int i=0;i<word.length();i++){
            string sub = "";
            for(int j=i;j<word.length();j++){
                sub+=word[j];
                v.push_back(sub);
            }
        }
        int ans=0;
        for(int j=0;j<v.size();j++){
            string temp = v[j];
            if(temp.size() < k+5)
                continue;
            int a=0,e=0,i=0,o=0,u=0,cons=k;
            for(char c:temp){
                if(c=='a'){
                    a++;
                }
                else if(c=='e'){
                    e++;
                }
                else if(c=='i'){
                    i++;
                }
                else if(c=='o'){
                    o++;
                }
                else if(c=='u'){
                    u++;
                }
                else{
                    cons--;
                }
            }
            if(a!=0 && e!=0 && i!=0 && o!=0 && u!=0 && cons==0){
                ans++;
            }
        }
        return ans;
    }
};