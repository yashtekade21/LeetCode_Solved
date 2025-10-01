class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        int emptyBottles = numBottles;

        while (emptyBottles / numExchange != 0) {
            int fullBottles = emptyBottles / numExchange;
            int extra = emptyBottles % numExchange;

            ans += fullBottles;
            emptyBottles = fullBottles + extra;
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
