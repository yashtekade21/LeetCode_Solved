class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int ans = 0;

        int i = 0, j = n - 1;
        while (i < j) {
            int pairSum = nums[i] + nums[j];
            ans = max(ans, pairSum);
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
