class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = n + 1, i = 0;
        vector<int> bits(32, 0);

        for (int j = 0; j < n; j++) {
            check(bits, nums[j], 1);
            while (i <= j && bitsToNumber(bits) >= k) {
                ans = min(ans, j - i + 1);
                check(bits, nums[i++], -1);
            }
        }
        if (ans == n + 1)
            return -1;

        return ans;
    }

private:
    void check(vector<int>& bits, int num, int val) {
        for (int i = 0; i < 32; i++)
            if ((num >> i) & 1)
                bits[i] += val;
    }

    int bitsToNumber(vector<int>& bits) {
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (bits[i] != 0)
                ans |= 1 << i;
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
