class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> validWords;
        for (auto& start : startWords) {
            sort(start.begin(), start.end());
            for (char c = 'a'; c <= 'z'; c++) {
                string transformed = start + c; 
                sort(transformed.begin(), transformed.end());
                validWords.insert(transformed);
            }
        }
        int count = 0;
        for (auto& target : targetWords) {
            sort(target.begin(), target.end());
            if (validWords.count(target)) {
                count++;
            }
        }

        return count;
    }
};
