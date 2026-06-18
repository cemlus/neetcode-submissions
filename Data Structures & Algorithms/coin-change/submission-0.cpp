class Solution {
public:
    int func(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){
        // remember that we are counting coins
        if(idx == 0){
            if(amount % coins[idx] == 0) return amount/coins[idx];
            return 1e7;
        }
        if(dp[idx][amount] != -1e7) return dp[idx][amount];

        // 0 coins picked
        int notPick = 0 + func(coins, amount, idx - 1, dp);
        int pick = 1e7;
        if(amount >= coins[idx]){
            // 1 coin picked;
            pick = 1 + func(coins, amount - coins[idx], idx, dp);
        }
        return dp[idx][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), (vector<int>(amount + 1, -1e7)));
        int ans = func(coins, amount, coins.size() - 1, dp);
        return (ans == 1e7) ? -1 : ans;
    }
};
