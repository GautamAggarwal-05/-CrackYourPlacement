class Solution {
public:

    vector<int> computeLPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0;  // length of the previous lps
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];  // Fallback to the previous longest prefix suffix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


vector<int> KMP(const string &text, const string &pattern) {
    vector<int> lps = computeLPS(pattern);  // Compute LPS array
    int n = text.length();
    int m = pattern.length();
    int i = 0;  
    int j = 0;  
    vector<int> results;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            results.push_back(i - j);  // Pattern found at index (i - j)
            j = lps[j - 1];  // Use LPS to shift the pattern
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];  // Shift the pattern using the LPS array
            } else {
                i++;
            }
        }
    }
    return results;
}


    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>i_indices = KMP(s,a);
        vector<int>j_indices = KMP(s,b);
        vector<int>ans;
        for(auto elem : i_indices){
            int left_limit = elem-k;
            int right_limit = elem+k;
            int low = 0;
            int high = j_indices.size()-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(j_indices[mid]>=left_limit && j_indices[mid]<=right_limit){
                    ans.push_back(elem);
                    break;
                }
                else if(j_indices[mid]<left_limit){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};