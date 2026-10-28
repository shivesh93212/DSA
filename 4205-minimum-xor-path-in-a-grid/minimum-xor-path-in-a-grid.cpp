class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<unordered_set<int>> dp(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                unordered_set<int> curr;

                if (i == 0 && j == 0) {
                    curr.insert(grid[i][j]);
                } else {
                    if (i > 0) {
                        for (int x : dp[j]) {
                            curr.insert(x ^ grid[i][j]);
                        }
                    }

                    if (j > 0) {
                        for (int x : dp[j - 1]) {
                            curr.insert(x ^ grid[i][j]);
                        }
                    }
                }

                dp[j] = move(curr);
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};