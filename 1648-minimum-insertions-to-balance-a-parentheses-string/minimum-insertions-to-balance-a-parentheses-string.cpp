class Solution {
public:
    int minInsertions(string s) {
        int ans=0;

        stack<char>st;

        for(int i=0;i<s.size();i++){

            if(s[i]=='('){
                st.push(s[i]);
            }

            if(s[i]==')' && st.empty()){
                st.push('(');
                ans+=1;
                if(i<s.size() && s[i+1]==')'){
                    i++;
                    st.pop();
                }
                else{
                    ans++;
                    st.pop();
                }

            }

            if(s[i]==')' && !st.empty()){
                if(i<s.size() && s[i+1]==')'){
                    i++;
                    st.pop();
                }
                else{
                    ans++;
                    st.pop();
                }

            }
                 
            }
            if(!st.empty()){
                ans+=2*st.size();
            }

            return ans;
        
    }
};