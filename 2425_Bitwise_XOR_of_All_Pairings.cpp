class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int xor_1 = 0, xor_2 = 0;

        for (auto& i : nums1) {
            xor_1 ^= i;
        }

        for (auto& i : nums2) {
            xor_2 ^= i;
        }

        if (n1 % 2 == 0 && n2 % 2 == 0)
            return 0;
        else if (n1 % 2 == 0) {
            return xor_1;
        } else if (n2 % 2 == 0) {
            return xor_2;
        }

        return xor_1 ^ xor_2;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
