class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> mp;

        for (auto& point : points) {
            int y = point[1];

            mp[y]++;
        }

        long long ans = 0, prev = 0;

        for (auto& it : mp) {
            int cnt = it.second;

            long long horizontalLines = (long long)cnt * (cnt - 1) / 2;

            ans += horizontalLines * prev;
            prev += horizontalLines;
        }
        return ans % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
