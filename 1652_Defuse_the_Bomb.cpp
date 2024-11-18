class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;

        int l = 0, sum = 0;
        for (int r = 0; r < n + abs(k); r++) {
            sum += code[(r + n) % n];

            if (r - l + 1 > abs(k)) {
                sum -= code[(l + n) % n];
                l = (l + 1 + n) % n;
            }
            if (r - l + 1 == abs(k)) {
                if (k > 0)
                    ans[(l - 1 + n) % n] = sum;
                else if (k < 0)
                    ans[(r + 1 + n) % n] = sum;
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
