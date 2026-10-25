class Solution {
public:

   bool solve(vector<vector<int>>& grid , int i ,int j , int n , int m ){
    if(i>=n || i<0 ||j<0 || j>=m){
        return false;
    }

    if(grid[i][j]==1){
        return true;
    }
    grid[i][j]=1;

    bool left  =solve(grid,i,j-1,n,m);
    bool right =solve(grid,i,j+1,n,m);
    bool up    = solve(grid,i-1,j,n,m);
    bool down  = solve(grid , i+1,j,n,m);
    
    return left && right && up && down;
   }
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m=grid[0].size();


        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                if(solve(grid,i,j,n,m)) ans++;
            }
            }
        }
        return ans;
    }
};