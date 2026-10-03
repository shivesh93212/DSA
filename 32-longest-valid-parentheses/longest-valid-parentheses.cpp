class Solution {
public:
    int longestValidParentheses(string s) {
       int  n= s.size();

       vector<int>temp(n,0);
       stack<int>st;
       for(int i=0;i<n;i++){
           if(s[i]=='('){
            st.push(i);
            continue;
           }

           if(!st.empty()){
            int t=st.top();
            st.pop();
            temp[i]=1;
            temp[t]=1;
           }
           
       } 

       int ans=0;
       int c=0;
       for(auto & val : temp){
        if(val==1){
            c++;
        }
        else{
            ans=max(ans,c);
            c=0;
        }
        
       }
       ans=max(ans,c);
       return  ans;
    }
};