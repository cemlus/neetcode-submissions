class Solution {
public:
    bool func(string& s, unordered_set<string> &dict, int startIdx, vector<int>& dp){
        if(startIdx == s.length()){
            return true;
        }
        if(dp[startIdx] != -1) return dp[startIdx];

        for(int i = startIdx + 1; i <= s.length() ; i++){
            string currWord = s.substr(startIdx, i - startIdx);

            if(dict.count(currWord) == true){
                if(func(s, dict, i, dp)){           // word break found move on to the next word and therefore start 
                                                // a new start index which would be the end of the previous one
                    return dp[startIdx] = true;
                }
            }
        }

        return dp[startIdx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, -1);
        return func(s, dict, 0, dp);
    }
};
