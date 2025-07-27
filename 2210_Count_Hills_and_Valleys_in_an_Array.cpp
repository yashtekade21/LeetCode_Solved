class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int j = 1, i = 0;
        while (j+1 < n) {
            if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||
                (nums[i] > nums[j] && nums[j] < nums[j + 1])) {
                i = j;
                ans++;
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
