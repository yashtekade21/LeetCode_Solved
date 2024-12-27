class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), max_score = INT_MIN;

        int max_i_val = values[0] + 0;
        for (int j = 1; j < n; j++) {
            int j_val = values[j] - j, i_val = max_i_val;
            max_score = max(max_score, i_val + j_val);

            max_i_val = max(max_i_val,values[j] + j);
        }
        return max_score;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
