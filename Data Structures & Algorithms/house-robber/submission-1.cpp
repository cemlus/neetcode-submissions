class Solution {
public:
    int rob(vector<int>& nums) {
        // to ensure maximum money i will either rob all the 
        // even houses or the odd houses
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int neg = (i > 1) ? dp[i - 2] : 0;
            int pick = nums[i] + neg;
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};
