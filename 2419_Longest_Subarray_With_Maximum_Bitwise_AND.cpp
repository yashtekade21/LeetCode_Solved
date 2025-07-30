class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxAND = *max_element(nums.begin(), nums.end());

        int i = 0;
        int ans = 0, maxLen = 0;

        while (i < n) {
            if (nums[i] == maxAND) {
                while (i < n && nums[i] == maxAND) {
                    maxLen++;
                    i++;
                }

                ans = max(ans, maxLen);
                maxLen = 0;
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
