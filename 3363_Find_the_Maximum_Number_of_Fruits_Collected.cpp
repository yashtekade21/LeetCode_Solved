class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        dp.resize(n, vector<int>(n, -1));

        return child1Collect(fruits) + child2Collect(0, n - 1, fruits) +
               child3Collect(n - 1, 0, fruits);
    }

private:
    int child1Collect(vector<vector<int>>& fruits) {
        int diag = 0;
        for (int i = 0; i < n; i++)
            diag += fruits[i][i];
        return diag;
    }

    int child2Collect(int i, int j, vector<vector<int>>& fruits) {
        if (i >= n || j < 0 || j >= n)
            return 0;

        if (i == n - 1 && j == n - 1)
            return 0;

        if (i == j || i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int bottomLeft = fruits[i][j] + child2Collect(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collect(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collect(i + 1, j + 1, fruits);

        return dp[i][j] = max({bottomLeft, bottomDown, bottomRight});
    }

    int child3Collect(int i, int j, vector<vector<int>>& fruits) {
        if (i >= n || j < 0 || j >= n)
            return 0;

        if (i == n - 1 && j == n - 1)
            return 0;

        if (i == j || i < j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int topRight = fruits[i][j] + child3Collect(i - 1, j + 1, fruits);
        int top = fruits[i][j] + child3Collect(i, j + 1, fruits);
        int bottomRight = fruits[i][j] + child3Collect(i + 1, j + 1, fruits);

        return dp[i][j] = max({topRight, top, bottomRight});
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
