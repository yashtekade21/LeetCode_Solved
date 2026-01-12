class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i + 1][0], y2 = points[i + 1][1];

            int dx = abs(x2 - x1), dy = abs(y2 - y1);

            ans += (min(dx, dy) + abs(dy - dx));
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
