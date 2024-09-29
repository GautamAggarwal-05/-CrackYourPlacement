class Solution {
public:
    char kthCharacter(int k) {
        string original="a";
        
        while(original.size() < k){
            string generated="";
            for(char c:original){
                generated += (c+1)%122;
            }
            original=original+generated;
        }
        return original[k-1];

    }
};