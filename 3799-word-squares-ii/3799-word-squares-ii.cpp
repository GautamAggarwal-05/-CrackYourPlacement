class Solution {
public:
    bool checkwordsquare(vector<string>& words){
        if(words[0][0]==words[1][0] && words[0][3]==words[2][0] && words[3][0]==words[1][3] && words[3][3]      ==words[2][3]){
            return true;
        }
        return false;
    }
    // generate all the permutations of given vector and then check for the condition
    void generate_permutations(int i,vector<string>&permutation,vector<vector<string>>&result){
        if(i==permutation.size()){
            if(checkwordsquare(permutation))
                result.push_back(permutation);
        }

        for(int j=i;j<permutation.size();j++){
            swap(permutation[i],permutation[j]);
            generate_permutations(i+1,permutation,result);
            swap(permutation[i],permutation[j]);
        }

    }
    // generate all subsequence of length 4 
    void solve(int i,vector<string>&curr,vector<string>words,vector<vector<string>>&result){
      if(curr.size()==4){
        generate_permutations(0,curr,result);
        return;
      }

      if(i==words.size())
        return;
    
        curr.push_back(words[i]);
        solve(i+1,curr,words,result);
        curr.pop_back();
        solve(i+1,curr,words,result);
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>result;
        //words[0]=top words[1]=left words[2]=right words[3]=bottom
        vector<string>curr;
        solve(0,curr,words,result);
        sort(result.begin(),result.end());
        return result;
    }
};


