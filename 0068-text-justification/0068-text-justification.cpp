class Solution {
public:
    string findLine(int i,int j,int eachspace,int extraspace,vector<string>& words,int maxWidth){
        string line="";
        for(int k=i;k<j;k++){
            line += words[k];
            if(k==j-1)
                continue;
            for(int z=1;z<=eachspace;z++){
                line+=" ";
            }
            if(extraspace>0){
                line+=" ";
                extraspace--;
            }
        }

        while(line.length() < maxWidth){
            line+=" ";
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string>ans;
        int n = words.size();
        while(i<n){
            int spacecount=0;
            int lettercount = words[i].length();
            int j=i+1;

            while(j<n && (words[j].length()+1+lettercount+spacecount) <= maxWidth){
                lettercount +=words[j].length();
                spacecount++;
                j++;
            }
            int remainingSpace = maxWidth - lettercount;
            int eachspace=0;
            int extraspace=0;
            if(spacecount!=0){
                eachspace = remainingSpace/spacecount;
                extraspace = remainingSpace % spacecount;
            }

            if(j==n){ //last line
                eachspace = 1;
                extraspace = 0;
            }
            string Line = findLine(i,j,eachspace,extraspace,words,maxWidth);
            ans.push_back(Line);
            i=j;
        }
        return ans;
    }
};