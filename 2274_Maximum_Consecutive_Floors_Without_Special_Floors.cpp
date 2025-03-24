class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 && bottom < special[i]) {
                ans = max(ans, special[i] - bottom);
            }
            if (i == n - 1 && top > special[i]) {
                ans = max(ans, top - special[i]);
            }

            if (i < n - 1) {
                ans = max(ans, special[i + 1] - special[i] - 1);
            }
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
