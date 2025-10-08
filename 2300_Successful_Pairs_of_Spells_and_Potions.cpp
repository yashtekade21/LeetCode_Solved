class Solution {
public:
    int n, m;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        n = spells.size(), m = potions.size();

        vector<int> ans(n, 0);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            ans[i] = solve(potions, success, spells[i]);
        }
        return ans;
    }

private:
    int solve(vector<int>& potions, long long success, int spell) {
        int l = 0, r = m - 1;
        int idx = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            long long product = (long long)spell * potions[mid];

            if (product >= success) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return idx != -1 ? m - idx : 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
