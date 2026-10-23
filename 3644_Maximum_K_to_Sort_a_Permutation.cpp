class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(), k = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                k = (k & nums[i]);
        }

        return k == -1 ? 0 : k;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
