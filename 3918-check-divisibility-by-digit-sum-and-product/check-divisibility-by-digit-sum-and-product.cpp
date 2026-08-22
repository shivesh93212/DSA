class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int k=n;
        while(k!=0){
            int di=k%10;
            k=k/10;
            sum+=di;
            pro*=di;
           
        }
          
           return n % (sum + pro) == 0;
       }
};