class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        int ans=INT_MIN;
        while(left<right)
        {
            
            int currLeft = height[left], currRight = height[right];
            if (height[left] <= height[right]) {
                area=abs(left-right)*height[left];
                while (left < height.size() && height[left] <= currLeft) {
                    left++;
                } 
            } else {
                area=abs(left-right)*height[right];
                while (right >= 0 && height[right] <= currRight) {
                    right--;
                }
            }
            ans=max(ans,area);
        }
        return ans;
    }
};