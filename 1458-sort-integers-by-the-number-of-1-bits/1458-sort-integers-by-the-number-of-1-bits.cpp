class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>onebit;
        for(int i=0;i<n;i++){
            int num = arr[i];
            int count=0;
            while(num!=0){
                int bit = num & 1;
                num = num >> 1;
                if(bit==1)
                    count++;
            }
            cout<<count<<endl;
            onebit.push_back({count,arr[i]});
        }

        sort(onebit.begin(),onebit.end());
        vector<int>ans;
        for(auto elem:onebit){
            ans.push_back(elem.second);
        }
        return ans;
    }
};