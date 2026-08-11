class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int sum=0;
        int currlen=0;

        for(int i=0;i<nums.size();i++){
            int cnt=1;
            int currsum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j-1]<nums[j] && nums[j-1]+1==nums[j]){
                    currsum+=nums[j];
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(currlen<cnt){
                sum=currsum;
                currlen=cnt;
            }
            break;
        }

        while(true){
            if(!st.count(sum)){
                return sum;
            }
            sum++;
        }
        return -1;
    }
};