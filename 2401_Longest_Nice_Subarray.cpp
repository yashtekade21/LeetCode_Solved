class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int curBitAnd = 0, i = 0, j = 0;
        int k = 1;

        while (j < n) {
            while ((curBitAnd & nums[j]) != 0) {
                curBitAnd ^= nums[i];
                i++;
            }

            k = max(k, j - i + 1);
            curBitAnd |= nums[j];

            j++;
        }
        return k;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
