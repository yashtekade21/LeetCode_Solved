class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;

        while (ans <= n) {
            if (ans >= n)
                break;

            ans = ans * 2 + 1;
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
