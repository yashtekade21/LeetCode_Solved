class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int i = 0, j = n - 1, ans = INT_MAX;
        while (i <= j) {
            if (nums[i] == target)
                ans = min(ans, abs(i - start));
            if (nums[j] == target)
                ans = min(ans, abs(j - start));

            if (ans == 0)
                return 0;
            i++;
            j--;
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
