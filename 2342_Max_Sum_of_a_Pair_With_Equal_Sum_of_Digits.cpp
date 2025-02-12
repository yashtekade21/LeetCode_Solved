class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = -1;

        vector<int> mp(82, 0);

        for (int i = 0; i < n; i++) {
            int digit_sum = get_digit_sum(nums[i]);

            if (mp[digit_sum] != 0) {
                max_sum = max(mp[digit_sum] + nums[i], max_sum);
            }
            mp[digit_sum] = max(mp[digit_sum], nums[i]);
        }
        return max_sum;
    }

private:
    int get_digit_sum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
