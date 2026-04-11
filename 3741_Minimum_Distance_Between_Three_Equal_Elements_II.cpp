class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]].emplace_back(i);

        int ans = INT_MAX;
        for (auto& data : mp) {
            int len = data.second.size();
            if (len < 3)
                continue;

            int num = data.first;
            vector<int>& idxes = data.second;

            for (int idx = 0; idx < len - 2; idx++) {
                int i = idx, j = idx + 1, k = idx + 2;
                int val = abs(idxes[j] - idxes[i]) + abs(idxes[k] - idxes[j]) +
                          abs(idxes[k] - idxes[i]);
                ans = min(ans, val);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
