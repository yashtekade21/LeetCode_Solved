class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 == 0 && nums[i + 1] % 2 != 0)
                continue;
            else if (nums[i] % 2 != 0 && nums[i + 1] % 2 == 0)
                continue;
            else
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
