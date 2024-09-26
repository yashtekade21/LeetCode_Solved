class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int count = 0;
        int max_bitwise_and = *max_element(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == max_bitwise_and) {
                while (i < nums.size() && nums[i++] == max_bitwise_and)
                    count++;

                k = max(k, count);
                count = 0;
            } else
                i++;
        }

        return k;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
