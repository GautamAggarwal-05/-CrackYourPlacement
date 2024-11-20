class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (char c : s) {
            mp[c]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }
        int start = 0, maxLength = 0;
        for (int end = 0; end < n; end++) {
            mp[s[end]]--;
            while (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
                mp[s[start]]++;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return n - maxLength;
    }
};
