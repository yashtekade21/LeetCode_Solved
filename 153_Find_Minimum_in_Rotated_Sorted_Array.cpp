class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int idx;
        for (idx = 0; idx < n - 1; idx++) {
            if (nums[idx] > nums[idx + 1])
                break;
        }

        return min(binSearch(nums, 0, idx), binSearch(nums, idx + 1, n - 1));
    }

private:
    int binSearch(vector<int>& arr, int l, int r) {
        int target = arr[0];

        while (l <= r) {
            int m = (l + r) / 2;

            if (arr[m] < target) {
                target = arr[m];
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return target;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
