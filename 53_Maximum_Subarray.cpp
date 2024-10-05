class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxSum)
                maxSum = sum;

            if (sum < 0)
                sum = 0;
        }
        // if (maxSum < 0)
        //     maxSum = 0;

        return maxSum;
    }
};
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
