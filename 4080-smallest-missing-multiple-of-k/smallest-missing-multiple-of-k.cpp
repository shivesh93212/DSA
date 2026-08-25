class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
         int ele=*max_element(nums.begin(),nums.end());

       
         int num=k;
         while(num<=ele){
         
            num+=k;
         }

         unordered_set<int>s;
         for(auto & num : nums){
            s.insert(num);
         }

       
           int n=k;
         for(int i=0;i<nums.size();i++){
             if(s.find(n)==s.end()){
                return n;
          }
          n+=k;
         }
         return num;
    }
};