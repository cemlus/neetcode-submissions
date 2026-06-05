class Solution {
public:
    int climbStairs(int n) {
        // in order to get to 45 you must first get to 44 and 43
        // in order to get to 3 you must get to 1 and 2
        // in order to get to 4 you must get to 2 and 3
        if(n <= 2) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        } 
        return dp[n];
    }
};