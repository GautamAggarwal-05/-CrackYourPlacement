class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int m=0;
        int currend=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i]>m){ // max jump till now we can make but do we need this jump that we get to know with the help of second condition i==currend means abh mai vaha tak pauch gaya jaha tak jaa sakta tha but yeh to end nahi hai means ek jump lena padega toh max vala lelete hai toh abh hamara currend change ho gaya means abh ham m tak pauch sakte hai.
                m=i+nums[i];
            }
            if(i==currend){
                ans++;
                currend=m;
            }
        }
        return ans;
    }
};