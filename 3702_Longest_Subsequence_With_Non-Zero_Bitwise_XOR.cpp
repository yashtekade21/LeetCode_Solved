class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        bool flag = true;

        for (auto& num : nums) {
            ans = (ans ^ num);

            if (num != 0)
                flag = false;
        }

        if (flag)
            return 0;

        return (ans == 0) ? n - 1 : n;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
