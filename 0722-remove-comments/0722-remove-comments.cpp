class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int n = source.size();
        vector<string> ans;
        
        for (int i = 0; i < n; i++) {
            string line = source[i];
            int len = line.length();
            string temp = "";
            int itr = 0;

            while (itr < len) {
                if (itr + 1 < len && line[itr] == '/' && line[itr + 1] == '/') {
                    break; 
                }
                else if (itr + 1 < len && line[itr] == '/' && line[itr + 1] == '*') {
                    itr += 2; 
                    
                    while (true) {
                        while (itr < len && !(line[itr] == '*' && itr + 1 < len && line[itr + 1] == '/')) {
                            itr++;
                        }
                        
                        if (itr == len) { 
                            i++;
                            if (i >= source.size())
                                break;
                            line = source[i];
                            len = line.length();
                            itr = 0;
                        } else { 
                            itr += 2;
                            break;
                        }
                    }
                } else {
                    temp.push_back(line[itr]);
                    itr++;
                }
            }

            if (!temp.empty()) {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
