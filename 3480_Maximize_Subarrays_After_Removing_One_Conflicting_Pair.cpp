class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long validSubs = 0;

        unordered_map<int, vector<int>> conflictPoints;

        for (auto& p : conflictingPairs) {
            int x = min(p[0], p[1]);
            int y = max(p[0], p[1]);

            conflictPoints[y].push_back(x);
        }

        int maxConflictPoint = 0, secMaxConflictPoint = 0;

        vector<long long> extraSubs(n + 1, 0);

        for (int point = 1; point <= n; point++) {
            for (auto& u : conflictPoints[point]) {
                if (u >= maxConflictPoint) {
                    secMaxConflictPoint = maxConflictPoint;
                    maxConflictPoint = u;
                } else if (u > secMaxConflictPoint) {
                    secMaxConflictPoint = u;
                }
            }

            validSubs += point - maxConflictPoint;
            extraSubs[maxConflictPoint] +=
                maxConflictPoint - secMaxConflictPoint;
        }
        return validSubs + *max_element(extraSubs.begin(), extraSubs.end());
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
