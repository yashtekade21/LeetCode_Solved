class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int cnt = 1, i = 0;

        for (int j = 0; j < n; j++) {
            if (j > 0 && nums[j] == nums[j - 1] + 1)
                cnt++;

            if (j - i + 1 > k) {
                if (nums[i] + 1 == nums[i + 1])
                    cnt--;
                i++;
            }

            if (j - i + 1 == k && cnt == k)
                ans[i] = nums[j];
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
