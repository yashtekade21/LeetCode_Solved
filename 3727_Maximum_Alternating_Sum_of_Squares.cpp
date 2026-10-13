class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });

        for (auto& n : nums) {
            cout << n << endl;
        }
        int i = 0, m = n / 2;

        while (i < m) {
            ans += (nums[i] * nums[i]) - (nums[n - i - 1] * nums[n - i - 1]);
            i++;
        }

        if (n % 2 != 0)
            ans += (nums[m] * nums[m]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
