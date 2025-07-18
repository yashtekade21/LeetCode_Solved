class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int n = size / 3;

        vector<long long> leftMinSum(size, 0), rightMaxSum(size, 0);

        priority_queue<int> leftPQ;
        priority_queue<int, vector<int>, greater<int>> rightPQ;
        long long leftSum = 0, rightSum = 0;

        for (int i = 0; i < 2 * n; i++) {
            leftPQ.push(nums[i]);
            leftSum += nums[i];

            if (leftPQ.size() > n) {
                leftSum -= leftPQ.top();
                leftPQ.pop();
            }

            leftMinSum[i] = leftSum;
        }

        for (int i = size - 1; i >= n; i--) {
            rightPQ.push(nums[i]);
            rightSum += nums[i];

            if (rightPQ.size() > n) {
                rightSum -= rightPQ.top();
                rightPQ.pop();
            }

            rightMaxSum[i] = rightSum;
        }

        long long ans = LLONG_MAX;

        for (int i = n - 1; i <= (2 * n - 1); i++)
            ans = min(ans, (long long)leftMinSum[i] - rightMaxSum[i + 1]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
