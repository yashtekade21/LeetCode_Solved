class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                return nums[i + 1];
        }

        return nums[0];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
