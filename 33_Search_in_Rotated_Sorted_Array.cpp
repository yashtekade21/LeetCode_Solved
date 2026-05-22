class Solution {
public:
    int n;
    int search(vector<int>& nums, int target) {
        n = nums.size();
        int l = 0, m, r = n - 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                m = i;
                break;
            }
        }

        int ans1 = binSearch(nums, l, m, target),
            ans2 = binSearch(nums, m + 1, r, target);
        return (ans1 != -1) ? ans1 : (ans2 != -1) ? ans2 : -1;
    }

private:
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target)
                return m;

            if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
