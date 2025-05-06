class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] = nums[i] + n * (nums[nums[i]] % n);

        for (int i = 0; i < n; i++)
            nums[i] /= n;

        return nums;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
