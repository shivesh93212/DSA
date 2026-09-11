class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int arr[10]={0};

        for(auto & val :  digits){
            arr[val]++;
        }

        int ans=0;

        for(int j=100;j<999;j+=2){
            int i=j;
            int c=i%10;
            i/=10;

            int b=i%10;
            i/=10;

            int a=i%10;
            i/=10;

            int temp[10]={0};
            temp[a]++;
            temp[b]++;
            temp[c]++;

            bool check=true;

            for(int d=0;d<=9;d++){
                 if(temp[d]>arr[d]){
                    check=false;
                    break;
                 }
            }

            if(check){
                ans++;
            }

        }
        return ans;
    }
};