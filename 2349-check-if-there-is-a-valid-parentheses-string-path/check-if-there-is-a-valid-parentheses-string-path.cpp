class Solution {
public:
 int dp[101][101][1000];
bool solve(vector<vector<char>>&grid , int i , int j , int cnt){
          if(i>=grid.size() || j>=grid[0].size()){
            return false;
          }

          if(grid[i][j]== '('){
            cnt++;
          }
          else{
            cnt--;
          }

          if(cnt<0){

            return false;
          }

          if((i==grid.size()-1 && j==grid[0].size()-1)){
            return cnt==0;
          }
          if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
          }


          return dp[i][j][cnt]=(solve(grid,i+1,j,cnt)||
                 solve(grid,i,j+1,cnt));

          
}
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};