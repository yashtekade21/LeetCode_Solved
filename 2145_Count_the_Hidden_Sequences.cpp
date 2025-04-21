class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        int minNum = 0, maxNum = 0;
        int currNum = 0;
        for (int i = 0; i < n; i++) {
            currNum = currNum + differences[i];

            minNum = min(minNum, currNum);
            maxNum = max(maxNum, currNum);

            if ((upper - maxNum) - (lower - minNum) + 1 <= 0)
                return 0;
        }
        return (upper - maxNum) - (lower - minNum) + 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
