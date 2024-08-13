class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int maxFreqCount = 0;
        for (char task : tasks) {
            mp[task]++;
            if (mp[task] > maxFreq) {
                maxFreq = mp[task];
                maxFreqCount = 1;
            } else if (mp[task] == maxFreq) {
                maxFreqCount++;
            }
        }

       
        int partCount = maxFreq - 1; 
        int partLength = n - (maxFreqCount - 1); 
        int emptySlots = partCount * partLength; 
        int availableTasks = tasks.size() - (maxFreq * maxFreqCount); 
        int idles = max(0, emptySlots - availableTasks);
        return tasks.size() + idles;
    }
};
