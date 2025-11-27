class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        int n = nums.size();

        vector<long long> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = nums[i] + prefSum[i - 1];
        }

        for (int i = 0; i < k; i++) {
            long long curSum = 0;
            int start = i;

            while (start < n && start + k - 1 < n) {
                int end = start + k - 1;

                long long subSum =
                    prefSum[end] - ((start > 0) ? prefSum[start - 1] : 0);

                curSum = max(subSum, curSum + subSum);
                ans = max(ans, curSum);
                start += k;
            }
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
