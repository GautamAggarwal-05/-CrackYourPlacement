class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        for(int i=0;i<n2;i++){
            mp[nums2[i]] = i;
        }

        for(int i=0;i<n1;i++){
            int indx = mp[nums1[i]];
            cout<<indx<<endl;
            int elem = nums2[indx];
            while(indx<n2 && elem>=nums2[indx]){
                indx++;
            }
            if(indx==n2){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(nums2[indx]);
        }
        return ans;
    }
};