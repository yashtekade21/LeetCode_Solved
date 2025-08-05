class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<bool> basUsed(n, false);
        int fruitsPlaced = 0;

        for (int i = 0; i < n; i++) {
            int amtFruit = fruits[i];
            for (int j = 0; j < n; j++) {
                int basCap = baskets[j];

                if (basCap >= amtFruit && basUsed[j] != true) {
                    fruitsPlaced++;
                    basUsed[j] = true;
                    break;
                }
            }
        }
        return n - fruitsPlaced;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
