class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for (auto& num : nums)
            ans += min(num % 3, 3 - (num % 3));

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
