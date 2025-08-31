class Solution {
public:
    int m, n;
    void solveSudoku(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        solve(board);
        return;
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == '.') {

                    for (char d = '1'; d <= '9'; d++) {

                        if (!hasDup(board, i, j, d)) {
                            board[i][j] = d;

                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool hasDup(vector<vector<char>>& board, int rowIdx, int colIdx, char d) {
        for (int i = 0; i < 9; i++) {
            if (i != colIdx && board[rowIdx][i] == d)
                return true;
            if (i != rowIdx && board[i][colIdx] == d)
                return true;
        }

        int rowStart = (rowIdx / 3) * 3;
        int colStart = (colIdx / 3) * 3;

        for (int i = rowStart; i < rowStart + 3; i++) {
            for (int j = colStart; j < colStart + 3; j++) {
                if (board[i][j] == d)
                    return true;
            }
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
