class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        
        int n = nums.size();

       vector<int>bit(32,0);

       for(auto & c : nums){
          for(int b=0;b<32;b++){
            if(c & (1LL<<b)){
                bit[b]++;
            }
          }
       }
       
       long long mod=1e9+7;

       long long result=0;

       while(k--){
        long long curr=0;

        for(int b=0;b<32;b++){
            if(bit[b]>0){
                bit[b]--;
                curr=(curr|(1LL<<b));
            }
        }

        result=(result+(curr*curr))%mod;
       }

       return result;
    }
};