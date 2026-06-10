class Solution {
   public:
    bool check(vector<vector<char>>& board, int i, int j, string word, int idx) {
        if (idx == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || j >= board[0].size() || i >= board.size()) {
            return false;
        }

        if (word[idx] != board[i][j]) {
            return false;
        }

        // mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = check(board, i + 1, j, word, idx + 1) ||
                     check(board, i - 1, j, word, idx + 1) ||
                     check(board, i, j + 1, word, idx + 1) || check(board, i, j - 1, word, idx + 1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]){
                    if(check(board, i, j, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
