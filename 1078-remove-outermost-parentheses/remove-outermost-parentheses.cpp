class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";

        int count=0;
        int i=0;
        int j=0;
        int n=s.size();

        while(j<n){
            if(s[j]=='('){
                count++;
            }
            else{
                if(count>1){
                    count--;
                }
                else{
                    count--;
                    ans+=s.substr(i+1,j-i-1);
                    i=j+1;
                   
                }
            }
            j++;
        }

        return ans;
    }
};