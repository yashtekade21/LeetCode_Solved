class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = nums[0];

        for (auto& num : nums)
            maxEl = max(num, maxEl);

        int ans = 0;
        for (auto& num : nums)
            ans += maxEl - num;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
