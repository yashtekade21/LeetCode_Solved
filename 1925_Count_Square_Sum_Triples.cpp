class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                long long a2plusb2 = pow(a, 2) + pow(b, 2);
                int num = sqrt(a2plusb2);

                if (a2plusb2 == num * num && num <= n) {
                    ans += 2;
                }
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
