class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int maxNum = INT_MIN;
        vector<int> ans;
        while (j < n) {
            maxNum = max(maxNum, nums[j]);

            if (j - i + 1 == k) {
                ans.emplace_back(maxNum);
                if (nums[i] == maxNum) {
                    maxNum = INT_MIN;
                    for (int z = i + 1; z < i + k; z++) {
                        maxNum = max(maxNum, nums[z]);
                    }
                }
                i++;
            }
            j++;
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
