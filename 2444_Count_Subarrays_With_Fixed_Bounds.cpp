class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int maxIdx = -1, minIdx = -1, culIdx = -1;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            culIdx = (nums[i] < minK || nums[i] > maxK) ? i : culIdx;
            minIdx = (nums[i] == minK) ? i : minIdx;
            maxIdx = (nums[i] == maxK) ? i : maxIdx;

            int left = min(minIdx, maxIdx);
            ans += max(0, (left - culIdx));
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
