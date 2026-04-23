class Solution {
public:
    bool isPalindromeRange(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                // try skipping left OR skipping right
                return isPalindromeRange(s, l + 1, r) ||
                       isPalindromeRange(s, l, r - 1);
            }
        }
        return true;
    }
};