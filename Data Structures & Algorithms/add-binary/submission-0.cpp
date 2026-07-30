class Solution {
   public:
    string addBinary(string a, string b) {
        int sum = 0;
        int carry = 0;
        string result = "";
        int m = a.length() - 1, n = b.length() - 1;
        while (m >= 0 || n >= 0) {
            sum = carry;

            if (m >= 0) {
                sum += a[m] - '0';  // doing this (- '0') cinverts the character into int
                m--;
            }

            if (n >= 0) {
                sum += b[n] - '0';
                n--;
            }

            char c = sum % 2 + '0';
            result += c;

            carry = sum / 2;
        }

        // in case carry is left to be added after both the strings have been finished
        if (carry) {
            result += carry + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};