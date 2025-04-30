class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (auto& num : nums) {
            int digits = (int)floor(log10(num)) + 1;
            ans += (digits % 2 == 0) ? 1 : 0;
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
