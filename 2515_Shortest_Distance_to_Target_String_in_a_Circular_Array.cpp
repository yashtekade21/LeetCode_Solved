class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int d = abs(i - startIndex);
                int cd = n - d;

                ans = min({ans, d, cd});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
