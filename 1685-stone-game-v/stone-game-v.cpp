class Solution {
public:
int dp[501][501];
int prefix[501];
int solve(vector<int>&stoneValue , int i , int j){
       if(i==j){
        return 0;
       }
     int ans=0;
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
    for(int k=i;k<j;k++){
         int leftSum = prefix[k + 1] - prefix[i];

            int rightSum = prefix[j + 1] - prefix[k + 1];
       
        if(leftSum<rightSum){
            ans=max(ans,leftSum+solve(stoneValue,i,k));
        }
        else if(leftSum>rightSum){
            ans=max(ans,rightSum+solve(stoneValue,k+1,j));
        }
        else{
            ans=max(ans, rightSum + max(solve(stoneValue, i, k),
                              solve(stoneValue, k+1, j)));
        }
    }
           return dp[i][j]=ans;
}
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        prefix[0] = 0;

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        return solve(stoneValue,0,n-1);

    }
};