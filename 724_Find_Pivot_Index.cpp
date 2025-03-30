class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        // int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left(n, 0), right(n, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        int pivotIdx = -1;

        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i];
            right[n - i - 1] = right[n - i] + nums[n - i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) {
                pivotIdx = i;
                break;
            }
        }
        return pivotIdx;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
