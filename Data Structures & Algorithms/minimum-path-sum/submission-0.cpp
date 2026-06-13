class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& cost) {
        // returning a large number so min() never chooses this dead-end when calculating the min(left, up)
        if (i < 0 || j < 0) {
            return 1e9;
        }
        if (i == 0 && j == 0) {
            return cost[0][0];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = func(i - 1, j, dp, cost) + cost[i][j];
        int left = func(i, j - 1, dp, cost) + cost[i][j];

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, dp, grid);
    }
};