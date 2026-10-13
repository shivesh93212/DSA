class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]*=-1;
            }
        }
        sort(nums.begin(),nums.end());

        long long ans=0;
        int n=nums.size();
        int i=0;
        int j=-1;
        int l=n%2;
        j=n/2;
        int k=j;

        while(j<n){
          if(k==i){
            break;
          }
          long long val1=nums[j]*nums[j];
          long long val2=nums[i]*nums[i];

          long long diff=abs(val1-val2);

          ans+=diff;

          i++;
          j++;
        }


        if(j<n){
            ans+=nums[j]*nums[j];
        }
        return ans;
    }
};