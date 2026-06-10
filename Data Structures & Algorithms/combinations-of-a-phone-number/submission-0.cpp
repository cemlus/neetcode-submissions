// 2 <= digits[i] <= 9
// 0 <= digits.length <= 4
class Solution {
   public:
    // idx1 -> for main tree
    // idx2 -> for subtree
    void generate(vector<string>& ans, string& curr, string& digits, unordered_map<int, string> mpp,
                  int idx) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string str = mpp[digits[idx] - '0'];

        for (char c : str) {
            curr.push_back(c);
            generate(ans, curr, digits, mpp, idx + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        unordered_map<int, string> mpp = {{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                                          {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> ans;
        string curr;
        generate(ans, curr, digits, mpp, 0);
        return ans;
    }
};
