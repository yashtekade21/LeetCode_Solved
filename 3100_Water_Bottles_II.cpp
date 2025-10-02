class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles - numExchange >= 0) {
            emptyBottles -= numExchange - 1;

            ans++;
            numExchange++;
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
