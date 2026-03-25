class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long sum = 0;

        if (sum % 2 != 0)
            return false;

        vector<long long> rowSum(m, 0), colSum(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        long long curSum = 0;
        for (int i = 0; i < m - 1; i++) {
            curSum += rowSum[i];
            if (curSum == (sum - curSum))
                return true;
        }

        curSum = 0;
        for (int j = 0; j < n - 1; j++) {
            curSum += colSum[j];
            if (curSum == (sum - curSum))
                return true;
        }

        return false;
    }
};
