class Solution {
public:
    string convertDateToBinary(std::string date) {
        string year = date.substr(0, 4);   // Extract year
        string month = date.substr(5, 2);  // Extract month
        string day = date.substr(8, 2);    // Extract day

        // Convert year to binary
        int num = stoi(year);
        year = "";
        while (num != 0) {
            int r = num % 2;
            year = to_string(r) + year;
            num = num / 2;
        }

        // Convert month to binary
        num = stoi(month);
        month = "";
        while (num != 0) {
            int r = num % 2;
            month = to_string(r) + month;
            num = num / 2;
        }

        // Convert day to binary
        num = stoi(day);
        day = "";
        while (num != 0) {
            int r = num % 2;
            day = to_string(r) + day;
            num = num / 2;
        }

        return year + '-' + month + '-' + day;
    }
};