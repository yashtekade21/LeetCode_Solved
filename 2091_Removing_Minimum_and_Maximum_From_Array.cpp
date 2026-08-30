class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxIdx = max_element(begin(nums), end(nums)) - begin(nums);

        int leftNum = min(minIdx, maxIdx);
        int rightNum = max(minIdx, maxIdx);

        return min({leftNum + 1 + n - rightNum, rightNum + 1, n - leftNum});
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
