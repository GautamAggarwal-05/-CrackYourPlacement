class Solution {
public:
    bool isOperator(char ch) {
        return (ch == '-' || ch == '+' || ch == '*');
    }

    vector<int> solve(int i, int j, vector<int>& num, vector<char>& op) {
        if (i == j)
            return {num[i]};

        vector<int> result;

        for (int k = i; k < j; k++) {
            vector<int> left = solve(i, k, num, op);
            vector<int> right = solve(k + 1, j, num, op);

            for (int l : left) {
                for (int r : right) {
                    if (op[k] == '+')
                        result.push_back(l + r);
                    else if (op[k] == '-')
                        result.push_back(l - r);
                    else if (op[k] == '*')
                        result.push_back(l * r);
                }
            }
        }

        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<char> op;
        vector<int> num;
        int n = expression.size();
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (isOperator(expression[i])) {
                op.push_back(expression[i]);
                num.push_back(stoi(temp));
                temp = "";
            } else {
                temp += expression[i];
            }
        }
        num.push_back(stoi(temp)); 

        return solve(0, num.size() - 1, num, op);
    }
};
