class Solution {
public:
    vector<string> findRepeatedDnaSequences(std::string s) {
        unordered_set<string> seen; 
        unordered_set<string> output;
        int n = s.length();
    
        for (int i = 0; i <= n - 10; ++i) {
            string sequence = s.substr(i, 10);
            if (seen.count(sequence) > 0) {
                output.insert(sequence);
            }
            seen.insert(sequence);
        }

        // Convert output set to vector
        return vector<string>(output.begin(), output.end());
    }
};

