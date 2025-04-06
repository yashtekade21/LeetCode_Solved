class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), prevIdx(n, -1);
        int lastIdx = 0, maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;
                    }

                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        lastIdx = i;
                    }
                }
            }
        }

        vector<int> ans;

        while (lastIdx != -1) {
            ans.emplace_back(nums[lastIdx]);
            lastIdx = prevIdx[lastIdx];
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
