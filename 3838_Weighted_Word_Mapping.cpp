class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (auto& word : words) {
            int sum = 0;
            for (auto& ch : word)
                sum += weights[ch - 'a'];
            sum %= 26;
            ans += ('z' - sum);
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
