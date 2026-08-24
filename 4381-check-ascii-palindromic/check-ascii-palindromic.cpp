class Solution {
public:
string solve(int ch){ 
    string value="";
    int c=0;
    while(c<8){
        c++;
     
       value += (ch % 2) + '0';
        ch/=2;
    }
    reverse(value.begin(),value.end());
    return value;
}
    bool isPalindromic(string s) {
        string temp="";
        int n=s.size();
        for(auto & ch  : s){
            temp+=solve(ch);
        }
        cout<<temp;

        int i=0;
        int j=temp.size()-1;

        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};