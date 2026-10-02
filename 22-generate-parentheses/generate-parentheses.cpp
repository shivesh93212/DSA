class Solution {
public:
vector<string>ans;
void solve(int open , int close, int n , string temp){
    if(open==n && close==n){
        ans.push_back(temp);
        return;
    }

    if(open<n){
        solve(open+1,close,n,temp+'(');
    }

    if(open>close){
        solve(open,close+1,n,temp+')');
    }
  
    
}
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");

        return ans;
    }
};