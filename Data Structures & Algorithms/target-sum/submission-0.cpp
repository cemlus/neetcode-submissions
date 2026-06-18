class Solution {
   public:
    int func(vector<int>& nums, int target, int idx, vector<unordered_map<int, int>>& dp) {
        if (idx == 0) {
            if (target == 0 && nums[0] == 0) return 2;  // we can both add and subtract 0
            if (abs(target) == nums[0])
                return 1;  // we can either add or subtract the number based on target's sign
            return 0;
        }

        if(dp[idx].count(target) == true) return dp[idx][target];
        int add = func(nums, target - nums[idx], idx - 1, dp);
        int sub = func(nums, target + nums[idx], idx - 1, dp);

        return dp[idx][target] = sub + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size());
        return func(nums, target, nums.size() - 1, dp);
    }
};
