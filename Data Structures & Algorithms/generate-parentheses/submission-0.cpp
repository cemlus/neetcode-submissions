class Solution {
public:
    void generate(vector<string>& ans, string str, int n, int open, int close){
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }
        if(open < n){
            generate(ans, str + "(", n, open + 1, close);
        }
        if(close < open){
            generate(ans, str + ")", n, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        generate(ans, str, n, 0, 0);
        return ans;
    }
};
