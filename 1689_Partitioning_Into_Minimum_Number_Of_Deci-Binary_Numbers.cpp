class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for (auto& num : n)
            ans = max(ans, num - '0');

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
