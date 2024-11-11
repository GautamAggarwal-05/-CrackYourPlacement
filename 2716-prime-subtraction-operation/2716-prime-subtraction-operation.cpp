class Solution {
public:
    bool isPrime[1000];
    void seive(){
        fill(isPrime,isPrime+1000,true);// initialize array ith all true
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<1000;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<1000;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
       seive();
        int n=nums.size();
       for(int i=n-2;i>=0;i--){ // peeche sai start kiya
        if(nums[i]<nums[i+1])// agar already chota hai skip
            continue;
        
        for(int p=2;p<nums[i];p++){ // check for smallest valid prime ->means minus karke next vale sai chota ho jaye
            if(!isPrime[p])
                continue;
            
            if(nums[i]-p < nums[i+1]){
                nums[i] -= p;
                break;
            }
        }
        if(nums[i] >= nums[i+1]) // agar abhi bhi bada hai means increasing nahi bana koi prime nahi mila jo isse chota bana paye
            return false;
       }
       return true;
    }
};
