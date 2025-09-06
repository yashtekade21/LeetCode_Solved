class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto& query : queries) {
            int l = query[0], r = query[1];

            ans += solve(l, r);
        }
        return ans;
    }

private:
    long long solve(int l, int r) {
        long long L = 1;
        long long S = 1;
        long long reqOp = 0;

        while (L <= r) {
            long long R = 4 * L - 1;

            long long start = max(L, (long long)l);
            long long end = min(R, (long long)r);

            if (start <= end)
                reqOp += (end - start + 1) * S;

            S++;
            L *= 4;
        }
        return (reqOp + 1) / 2;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
