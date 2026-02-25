class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto customSort = [](int& a, int& b) {
            int bitsInA = __builtin_popcount(a);
            int bitsInB = __builtin_popcount(b);

            if (bitsInA == bitsInB)
                return a < b;

            return bitsInA < bitsInB;
        };

        vector<int> ans = arr;
        sort(ans.begin(), ans.end(), customSort);
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
