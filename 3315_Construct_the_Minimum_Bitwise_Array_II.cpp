class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                continue;

            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) > 0)
                    continue;

                ans[i] = (nums[i] ^ (1 << (j - 1)));
                break;
            }
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
