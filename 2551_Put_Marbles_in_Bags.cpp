class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairSum(n - 1);

        for (int i = 0; i < n - 1; i++)
            pairSum[i] = weights[i] + weights[i + 1];

        sort(pairSum.begin(),pairSum.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; i++)
            ans += (pairSum[n - 2 - i] - pairSum[i]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
