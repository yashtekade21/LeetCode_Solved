class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                for (int k = i + 1; k <= n - 1; k++) {
                    ans = max(ans, calcArea(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }

private:
    double calcArea(vector<int>& a, vector<int>& b, vector<int>& c) {
        return 0.5 * abs(a[0] * b[1] + b[0] * c[1] + a[1] * c[0] - a[1] * b[0] -
                         b[1] * c[0] - a[0] * c[1]);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
