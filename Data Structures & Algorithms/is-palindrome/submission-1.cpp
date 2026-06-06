class Solution {
   public:
    bool isPalin(int start, string& s) {
        if (start >= s.length() / 2) return true;

        if (s[start] != s[s.length() - 1 - start]) return false;

        return isPalin(start + 1, s);
    }

    bool isPalindrome(string s) {
        string t;

        for (char c : s) {
            if (isalnum(c)) t += tolower(c);
        }

        return isPalin(0, t);
    }
};