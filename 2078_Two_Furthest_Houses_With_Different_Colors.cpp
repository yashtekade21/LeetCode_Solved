class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[0])
                ans = max(ans, i);

            if (colors[i] != colors[n - 1])
                ans = max(ans, n - i - 1);
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
