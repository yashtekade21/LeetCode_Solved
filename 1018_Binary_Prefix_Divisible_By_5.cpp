class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num = 0;
        int n = nums.size();
        vector<bool> ans(n, false);

        for (int i = 0; i < n; i++) {
            num = ((num * 2) + nums[i]) % 5;
            if (num == 0)
                ans[i] = true;
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
