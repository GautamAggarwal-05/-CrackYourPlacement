class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end(),greater<int>());
        int n=ages.size();
        int count=0;
        for(int x=0;x<n;x++){
            for(int y=x+1;y<n;y++){
                if(ages[y]<=(0.5*ages[x]+7))
                    break;
                if(ages[x]==ages[y])
                    count++;
                count++;
            }
        }
        return count;
    }
};