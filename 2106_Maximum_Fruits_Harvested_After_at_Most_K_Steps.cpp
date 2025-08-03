class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> fruitPositions(n), cumSumFruits(n);

        for (int i = 0; i < n; i++) {
            int pos = fruits[i][0];
            int amt = fruits[i][1];

            fruitPositions[i] = pos;
            cumSumFruits[i] = amt + (i - 1 >= 0 ? cumSumFruits[i - 1] : 0);
        }

        int ans = 0;

        for (int s = 0; s <= k / 2; s++) {
            // left -> right movement
            int i = startPos - s;
            int j = startPos + (k - 2 * s);

            int left =
                lower_bound(fruitPositions.begin(), fruitPositions.end(), i) -
                fruitPositions.begin();

            int right =
                upper_bound(fruitPositions.begin(), fruitPositions.end(), j) -
                fruitPositions.begin() - 1;

            if (left <= right) {
                int total = cumSumFruits[right] -
                            (left > 0 ? cumSumFruits[left - 1] : 0);
                ans = max(ans, total);
            }

            // right -> left movement

            i = startPos - (k - 2 * s);
            j = startPos + s;

            left =
                lower_bound(fruitPositions.begin(), fruitPositions.end(), i) -
                fruitPositions.begin();

            right =
                upper_bound(fruitPositions.begin(), fruitPositions.end(), j) -
                fruitPositions.begin() - 1;

            if (left <= right) {
                int total = cumSumFruits[right] -
                        (left > 0 ? cumSumFruits[left - 1] : 0);
                ans = max(ans, total);
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
