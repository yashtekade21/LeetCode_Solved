class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; i++) {
            ans.emplace_back(i);
            ans.emplace_back(-i);
        }

        if (n % 2 == 1)
            ans.emplace_back(0);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
