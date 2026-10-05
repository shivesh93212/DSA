class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;

        st.push(0);

        for(auto & c : s){
            if(c=='('){
                st.push(0);
            }
            else{
                int val=st.top();
                st.pop();
                int ans;

                if(val==0){
                    ans=1;
                }
                else{
                    ans=val*2;
                }
                st.top()+=ans;
            }
        }
        return st.top();
    }
};