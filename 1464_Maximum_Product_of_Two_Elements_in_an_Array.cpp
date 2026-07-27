class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        return (nums[0] - 1) * (nums[1] - 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
