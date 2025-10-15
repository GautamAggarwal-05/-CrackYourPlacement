class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n=str.length();
        int maxdigitindex=n-1;
        int swap1=-1;
        int swap2=-1;
        for(int i=n-2;i>=0;i--){
            if(str[i]<str[maxdigitindex]){
                swap1=i;
                swap2=maxdigitindex;
            }else if(str[i]>str[maxdigitindex]){
                maxdigitindex=i;
            }
        }
        if(swap1!=-1 && swap2!=-1)
            swap(str[swap1],str[swap2]);
        
        int ans = stoi(str);
        return ans;
    }

};