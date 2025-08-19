class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        int i = 0, j = 0;

        while (i < n) {
            if (nums[i] == 0) {
                j = i;
                while (j < n && nums[j] == 0)
                    j++;
                ans += static_cast<long long>(j - i) * (j - i + 1) / 2;
                i = j + 1;
            } else
                i++;
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
