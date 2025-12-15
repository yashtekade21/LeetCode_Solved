class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = n;

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && prices[j] - 1 == prices[j + 1])
                j++;

            long long len = j - i + 1;
            ans += (len * (len - 1)) / 2;
            i = j;
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
