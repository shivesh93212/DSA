class Solution {
public:
int dp[100001];
bool solve(int n){
    if(n==0){
        return false;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    for(int i=1;i*i<=n;i++){
        int square=i*i;
    if(!solve(n-square)){
    return dp[n]= true;
     }
    }
    
    return dp[n]=false;
}
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};