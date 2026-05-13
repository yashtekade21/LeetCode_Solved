class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int a, b, low, high, sum;
        vector<int> diffArr(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            a = nums[i];
            b = nums[n - 1 - i];

            low = min(a, b) + 1;
            high = max(a, b) + limit;

            sum = a + b;
            diffArr[2] += 2;
            diffArr[2 * limit + 1] -= 2;

            diffArr[low] -= 1;
            diffArr[high + 1] += 1;

            diffArr[sum] -= 1;
            diffArr[sum + 1] += 1;
        }

        int ans = INT_MAX, moves = 0;

        for (int target = 2; target <= 2 * limit; target++) {
            moves += diffArr[target];
            ans = min(ans, moves);
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
