class Solution {
public:
    string removeKdigits(string num, int k) {
    int n = num.size();
    if(n==k)
        return "0";
    string ans = "";
    for (char c : num) {
            // While the last character in ans is greater than the current character,
            // and we still have digits to remove, we remove the last character.
            while (!ans.empty() && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            // Append the current character to the result.
            ans.push_back(c);
        }

        // If we still have some k left, remove from the end of the result string.
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        
        ans = ans.substr(start);

    return ans.empty()?"0":ans;
    }
};