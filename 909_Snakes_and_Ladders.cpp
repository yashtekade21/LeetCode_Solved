class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        return bfs(board, n);
    }

private:
    int bfs(vector<vector<int>>& board, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);
        int moves = 0;
        visited[n - 1][0] = true;

        while (!q.empty()) {
            int nums = q.size();
            while (nums--) {
                int a = q.front();
                q.pop();

                if (a == n * n)
                    return moves;

                for (int i = 1; i <= 6; i++) {
                    int nextNum = a + i;
                    if (nextNum > n * n)
                        break;

                    int row = getRowCoOrd(nextNum, n);
                    int col = getColCoOrd(nextNum, n, row);

                    if (visited[row][col])
                        continue;
                    visited[row][col] = true;

                    if (board[row][col] == -1)
                        q.push(nextNum);
                    else
                        q.push(board[row][col]);
                }
            }
            moves++;
        }
        return -1;
    }

    int getRowCoOrd(int num, int n) {
        int row_top = (num - 1) / n;
        return (n - 1) - row_top;
    }

    int getColCoOrd(int num, int n, int row) {
        int col_left = (num - 1) % n;
        if ((row % 2 == 0 && n % 2 == 0) || (row % 2 == 1 && n % 2 == 1))
            return (n - 1) - col_left;

        return col_left;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
