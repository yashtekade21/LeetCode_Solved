class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        long long ans = 0,minLoss = LLONG_MAX;
        int op = 0;

        for (long long num : nums) {
            if ((num ^ k) > num) {
                ans += (num ^ k);
                op++;
            } else 
                ans += num;

            minLoss = min(minLoss, abs(num - (num ^ k)));
        }

        if (op % 2 == 1)
            ans -= minLoss;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
