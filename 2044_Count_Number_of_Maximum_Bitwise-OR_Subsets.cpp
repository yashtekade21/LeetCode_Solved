class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;

        for (auto& num : nums)
            maxOR |= num;

        return solve(nums, 0, 0, maxOR);
    }

private:
    int solve(vector<int>& nums, int idx, int OR, int& maxOR) {
        if (idx == nums.size()) {
            if (OR == maxOR)
                return 1;
            return 0;
        }

        int take = solve(nums, idx + 1, OR | nums[idx], maxOR);
        int not_take = solve(nums, idx + 1, OR, maxOR);

        return take + not_take;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
