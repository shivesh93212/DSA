class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(auto & c : s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
                continue;
            }

            if(st.empty() && (c==')' || c==']' || c=='}')){
                return false;
            }
            
            if(!st.empty() && st.top()=='(' && c==')'){
                st.pop();
                continue;
            }
            if(!st.empty()&& st.top()=='{' && c=='}'){
                st.pop();
                continue;
            }
            if(!st.empty() && st.top()=='[' && c==']'){
                st.pop();
                continue;
            }
            return false;
        }
        return st.empty();
    }
};