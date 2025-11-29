class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i]) % k;
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
