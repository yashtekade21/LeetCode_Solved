class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums)
            ans ^= i;

        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
