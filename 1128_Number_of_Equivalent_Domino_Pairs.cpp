class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mp;
        for (auto& vec : dominoes) {
            if (vec[0] > vec[1])
                swap(vec[0], vec[1]);
            string s = to_string(vec[0]) + "_" + to_string(vec[1]);
            mp[s]++;
        }

        int ans = 0;
        for (auto& [_, n] : mp) {
            if (n <= 1)
                continue;
            int pairs = (n * (n - 1)) / 2;
            ans += pairs;
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
