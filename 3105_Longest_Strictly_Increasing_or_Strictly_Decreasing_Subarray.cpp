class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int max_inc = 0, max_dec = 0;

        int inc = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                inc++;
            else {
                max_inc = max(max_inc, inc);
                inc = 1;
            }
        }

        max_inc = max(max_inc, inc);

        int dec = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                dec++;
            else {
                max_dec = max(max_dec, dec);
                dec = 1;
            }
        }

        max_dec = max(max_dec, dec);
        return max(max_inc, max_dec);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
