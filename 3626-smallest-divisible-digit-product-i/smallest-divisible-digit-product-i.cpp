class Solution {
public:
    int smallestNumber(int n, int t) {
        int k=n;
        while(true){
            long long pro=1;
            int val=k;
            while(val!=0){
                int g=val%10;
                pro*=g;
                val/=10;
            }
            if(pro%t==0){
                return k;
            }
            k++;
        }
        return -1;
    }
};