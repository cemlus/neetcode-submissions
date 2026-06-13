class Solution {
   public:
    int helper(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Fix 1: Handle empty vector slice safely
        
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int neg1 = (i > 1) ? dp[i - 2] : 0;
            int pick = nums[i] + neg1;
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Fix 2: Handle single house base case before slicing
        
        int ans1 = helper(std::vector<int>(nums.begin(), nums.begin() + n - 1));
        int ans2 = helper(std::vector<int>(nums.begin() + 1, nums.begin() + n));

        return max(ans1, ans2);
    }
};