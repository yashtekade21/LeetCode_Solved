class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long baseProfit = 0;
        for (int i = 0; i < n; i++)
            baseProfit += (long long)prices[i] * strategy[i];

        int i = 0, j = 0;
        long long unModifiedProfit = 0, modifiedProfit = 0, maxWinProfitMod = 0;
        while (j < n) {
            unModifiedProfit += (long long)prices[j] * strategy[j];

            if (j - i + 1 > k / 2)
                modifiedProfit += prices[j];

            if (j - i + 1 > k) {
                unModifiedProfit -= (long long)prices[i] * strategy[i];
                modifiedProfit -= prices[i + k / 2];
                i++;
            }

            if (j - i + 1 == k)
                maxWinProfitMod =
                    max(maxWinProfitMod, (modifiedProfit - unModifiedProfit));

            j++;
        }

        return baseProfit + maxWinProfitMod;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
