class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n=str.length();
        vector<int>maxRightIndex(n);// store the index of maximum value present in right of the curr value
        maxRightIndex[n-1]=n-1;
        // char maxi=str[n-1];
        for(int i=n-2;i>=0;i--){
            if(str[i]>str[maxRightIndex[i+1]]){
                maxRightIndex[i]=i;
            }else{
                maxRightIndex[i]=maxRightIndex[i+1];
            }
        }

        for(int i=0;i<n;i++){
            if(str[i]<str[maxRightIndex[i]]){
                swap(str[i],str[maxRightIndex[i]]);
                break;
            }
        }
        int ans=stoi(str);
        return ans;
    }
};