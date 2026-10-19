class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;

        for (auto& ch : nums) {
            cnt += (ch == target ? 1 : 0);
        }

        sort(nums.begin(), nums.end());
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> ans;
        for (int i = 0; i < cnt; i++)
            ans.push_back(idx++);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
