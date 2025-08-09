class Solution {
public:
     static bool comp(pair<int,int> &a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        vector<pair<int,int>>arr(env.size());
        for(int i = 0 ; i < env.size() ; i++){
            arr[i] = {env[i][0],env[i][1]};
        }

        sort(arr.begin(),arr.end(),comp);
        
        vector<int>ans;
        ans.push_back(arr[0].second);
        for(int i=1;i<env.size();i++)
        {
            if(arr[i].second > ans.back())
                ans.push_back(arr[i].second);
            else
            {
                int indx = lower_bound(ans.begin(),ans.end(),arr[i].second)-ans.begin();
                ans[indx]=arr[i].second;
            }
        }
        return ans.size();
    }
};