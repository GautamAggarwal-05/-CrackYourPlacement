class Solution {
public:
    vector<long long> power;
    unordered_map<string, int> mp;
    int solve(int i,int k,bool toggle,int jump){
        if(i>k+1)
            return 0;

        string key = to_string(i) + "_" + to_string(jump) + "_" + to_string(toggle);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }

        int ways=0;
        if(i==k){
            ways++;
        }

        if(toggle){
            ways += solve(i-1,k,false,jump);
        }
        ways += solve(i+pow(2,jump),k,true,jump+1);
        return  mp[key]=ways;
    }
    int waysToReachStair(int k) {
        power.resize(33);
        mp.clear();
        for(int i = 0; i < 33; ++i) {
            power[i] = pow(2, i);
        }
        return solve(1,k,true,0);
    }
};