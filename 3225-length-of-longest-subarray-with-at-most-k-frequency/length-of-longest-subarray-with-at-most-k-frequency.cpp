class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        
        
        int ans=0;

        int i=0;
        int j=0;

        while(j<nums.size()){
            mp[nums[j]]++;
            int freq=mp[nums[j]];
            if(freq<=k){
                j++;
            }
            else{
                ans=max(ans,j-i);
              
                // mp[nums[i]]++;
              
                while(mp[nums[j]]>k && i<j){
                    mp[nums[i]]--;
                    i++;
                }
                j++;
              
            }
        }
           ans=max(ans,j-i);

           return ans;
    }
};