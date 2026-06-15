class Solution {
   public:
    int func(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy) {
            profit =
                max(-prices[idx] + func(idx + 1, 0, prices, dp), 0 + func(idx + 1, 1, prices, dp));
        } else {
            profit =
                max(prices[idx] + func(idx + 1, 1, prices, dp), 0 + func(idx + 1, 0, prices, dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // base case
        dp[n][0] = dp[n][1] = 0;

        // recursion 0 -> n
        // tabulation n -> 0
        for (int idx = n - 1; idx >= 0 ; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[idx] + dp[idx + 1][0],
                                 0 + dp[idx + 1][1]);
                } else {
                    profit = max(prices[idx] + dp[idx + 1][1],
                                 0 + dp[idx + 1][0]);
                }
                dp[idx][buy] = profit;
            }
        }

        return func(0, 1, prices, dp);
    }
};
