class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        while (nums.size() != 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() - 1; i++) {
                newNums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = move(newNums);
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
