class Solution {
public:
int dp[101][101][2];
int solve(vector<int>&piles , int i , int  m , int person){
    if(i>=piles.size()){
        return 0;
    }

    if(dp[i][m][person]!=-1){
        return dp[i][m][person];
    }
    int a_take=0;

    int result;

    if(person==1)
    result=INT_MIN;
    else{
        result=INT_MAX;
    }
   
    
    for(int j=1;j<=min(m*2,(int)piles.size()-i);j++){

        a_take+=piles[i+j-1];
        
        if(person==1){
          result=max(result,a_take+solve(piles,i+j,max(m,j),0));
        }
        else{
            result=min(result,solve(piles,i+j,max(m,j),1));
        }

    }

    return dp[i][m][person]=result;
}
    int stoneGameII(vector<int>& piles) {

        memset(dp,-1,sizeof(dp));
        return solve(piles , 0,1,1);
    }
};