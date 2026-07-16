class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxNum(n, 0), prefixGcd(n, 0);

        for (int i = 0; i < n; i++) {
            maxNum[i] = (i == 0) ? nums[i] : max(maxNum[i - 1], nums[i]);

            prefixGcd[i] = __gcd(nums[i], maxNum[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            long long Gcd = __gcd(prefixGcd[i], prefixGcd[n - i - 1]);

            ans += Gcd;
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
