class Solution {
   public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, string& s, vector<string>& curr, int idx) {
        if (idx == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx ; i < s.length() ; i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(ans, s, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // subsets + isPalindrome
        vector<vector<string>> ans;
        vector<string> curr;
        solve(ans, s, curr, 0);
        return ans;
    }
};
