class Solution {
public:
    string reverseParentheses(string s) {
        

        stack<int>st;
      
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);

            }
            if(s[i]==')'){

                int val=st.top();
                st.pop();
 
                reverse(s.begin()+val,s.begin()+i);
            }
        }

        string ans="";
        for(auto & ch : s){
            if(isalpha(ch)){
                ans+=ch;
            }
        }

        return ans;
    }
};