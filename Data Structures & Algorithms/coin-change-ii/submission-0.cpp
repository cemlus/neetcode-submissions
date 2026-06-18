class Solution {
   public:
    int func(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        // remember that we are counting coins
        if (idx == 0) {
            if (amount % coins[idx] == 0) return 1;
            return 0;
        }
        if (dp[idx][amount] != -1) return dp[idx][amount];

        // 0 coins picked
        int notPick = func(coins, amount, idx - 1, dp);
        int pick = 0;
        if (amount >= coins[idx]) {
            // 1 coin picked;
            pick = func(coins, amount - coins[idx], idx, dp);
        }
        return dp[idx][amount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), (vector<int>(amount + 1, -1)));
        return func(coins, amount, coins.size() - 1, dp);

    }
};
