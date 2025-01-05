class Solution {
/*There can be 2^n subsequences using bit mask 0010101 etc we can see agar har subsequence ka bit mask nikale toh 
2^n bitmask ban sakte hai har bitmask ko vapis string mai convert karenge agar koi character 1 hai bitmask mai mtlb vo string ka part hai abh vo konsa character hai yeh kese pata chalega uss bit ko 1 sai and karke subseq mil gaya aggar 
vo pallindrome hai toh map mai push kardo with its length baad mai nest loop sai saare subseq ko ek dusre ki length sai
multiply karke dekh lo ki konsa bada hai */
public:
    int maxProduct(string s) {
        unordered_map<int, int> mp;
        int n = s.size();

        for(int mask = 0; mask < (1 << n); mask++){ // 1<<n == pow(2,n);
            string subseq;
            for(int j = 0; j < n; j++){
                if(mask & (1 << j)){// finding  character from bitmask
                    subseq.push_back(s[j]);
                }   
            }
            string rev = subseq;
            reverse(rev.begin(), rev.end());

            // If the subsequence is a palindrome, store its length
            if(subseq == rev){
                mp[mask] = subseq.size();
            }
        }

        int res = 0;

        // Iterate over all pairs of subsequences
        for(auto& subseq1 : mp){
            for(auto& subseq2 : mp){
                // Ensure the two subsequences don't overlap
                if((subseq1.first & subseq2.first) == 0){ // if 2 bitmask are different than there and is 0  
                    res = max(res, subseq1.second * subseq2.second);
                }
            }
        }

        return res;
    }
};