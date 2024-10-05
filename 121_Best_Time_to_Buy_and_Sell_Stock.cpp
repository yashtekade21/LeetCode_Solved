class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0], profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int x = prices[i] - minBuy;
            profit = max(profit, x);

            minBuy = min(minBuy, prices[i]);
        }
        return profit;
    }
};
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
