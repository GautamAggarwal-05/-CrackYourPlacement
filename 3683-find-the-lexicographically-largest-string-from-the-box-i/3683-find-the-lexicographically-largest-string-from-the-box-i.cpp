class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.length();
        //suppose i have 10 sweets and want to distribute in 7 frnd such that i get maxi amount and everyone get 1 sweet than this fromula ->
        if(numFriends==1)//no splitting
            return word;
        int windowsize = n-numFriends+1; //itni maximum size ki string ho sakti hai
        string maxi="";
        for(int i=0;i<n;i++){ 
            string curr = "";
            curr = word.substr(i,windowsize);// har index pai string 
            
            maxi=max(maxi,curr);// compare with previous largets string
        }
        return maxi;
    }
};