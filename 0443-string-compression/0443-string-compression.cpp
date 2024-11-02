class Solution {
public:
    int compress(vector<char>& chars) {
        int s = 0;           
        int n = chars.size();
        int count = 1;       
        for (int i = 1; i < n; i++) {
            if (chars[i] != chars[i - 1]) {  
                chars[s++] = chars[i - 1]; 
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[s++] = c;
                    }
                }
                count = 1;                  
            } else {
                count++;     
            }
        }
        chars[s++] = chars[n - 1];  

        if (count > 1) {                     
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[s++] = c;
            }
        }

        return s;
    }
};
