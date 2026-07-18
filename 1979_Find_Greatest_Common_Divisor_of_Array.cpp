class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;

        for (auto& num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        return __gcd(minVal, maxVal);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
