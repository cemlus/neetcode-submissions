class Solution {
public:
    int func(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i - 1] == s2[j - 1]){
            return dp[i][j] = 1 + func(s1, s2, i - 1, j - 1, dp);
        }
        
        return dp[i][j] = 0 + max(func(s1, s2, i - 1, j, dp), func(s1, s2, i, j - 1, dp));

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length() + 1, (vector<int>(text2.length() + 1, -1)));
        return func(text1, text2, text1.length(), text2.length(), dp);
    }
};
