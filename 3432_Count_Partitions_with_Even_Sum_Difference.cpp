class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long lefSum = 0, rigSum = 0;

        for (int i = 0; i < n - 1; i++) {
            lefSum += nums[i];
            rigSum = total - lefSum;

            if ((lefSum - rigSum) % 2 == 0)
                ans++;
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
