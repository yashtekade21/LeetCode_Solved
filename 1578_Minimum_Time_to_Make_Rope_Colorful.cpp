class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = 0, cur = 0;
        int ans = 0;

        for (int i = 0; i < colors.length(); i++) {
            if (i > 0 && colors[i - 1] != colors[i])
                prev = 0;

            cur = neededTime[i];
            ans += min(prev, cur);
            prev = max(cur, prev);
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
