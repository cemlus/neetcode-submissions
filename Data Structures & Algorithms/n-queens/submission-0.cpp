class Solution {
   public:
    bool isSafe(int col, int row, vector<string>& board, int n) {
        int r = row;
        int c = col;

        while (c >= 0) {
            if (board[r][c--] == 'Q') {
                return false;
            }
        }
        // check upper left diagonal
        c = col;
        r = row;
        while (r >= 0 && c >= 0) {
            if (board[r--][c--] == 'Q') {
                return false;
            }
        }
        c = col;
        r = row;
        // check lower left diagonal
        while (c >= 0 && r < n) {
            if (board[r++][c--] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(col, row, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, ans, board, n);
        return ans;
    }
};
