class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(int i=0;i<=nums.size()-k;i++){
            unordered_map<int,int>temp;
            for(int j=i;j<i+k;j++){
            if(temp.count(nums[j])){
                continue;
            }
             temp[nums[j]]++;
              
            }
            for(auto & [val,freq] : temp){
                mp[val]+=1;
            }
        }

        for(auto & [val,freq]  : mp){
            if(freq==1){
                ans=max(ans,val);
            }
        }
        return ans;
    }
};