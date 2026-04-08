class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2],
                v = queries[i][3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = ((long long)nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = 0;
        for (auto& num : nums)
            ans ^= num;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
