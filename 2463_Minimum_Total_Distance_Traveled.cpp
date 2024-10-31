class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](const vector<int> a, const vector<int> b) {
            return b[0] > a[0];
        });

        vector<int> factoryPos;
        for (auto v : factory) {
            for (int i = 0; i < v[1]; i++) {
                factoryPos.emplace_back(v[0]);
            }
        }

        int r = robot.size();
        int f = factoryPos.size();
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1, LLONG_MAX));
        
        dp[0][0] = 0;

        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= f; j++) {
                if (j < f) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                }
                if (i < r && j < f) {
                    long long distance = abs(robot[i] - factoryPos[j]);
                    if (dp[i][j] != LLONG_MAX) {
                        long long newDistance = dp[i][j] + distance;
                        if (newDistance < LLONG_MAX) 
                            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], newDistance);
                    }
                }
            }
        }

        long long result = LLONG_MAX;
        for (int j = 0; j <= f; j++) {
            result = min(result, dp[r][j]);
        }

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
