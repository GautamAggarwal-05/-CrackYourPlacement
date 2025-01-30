class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(sum < asteroids[i])
                return false;
            sum += asteroids[i];
        }
        return true;
    }
};