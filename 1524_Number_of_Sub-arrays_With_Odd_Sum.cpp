class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int cumSum = 0,evenSumCount = 1, oddSumCount = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            cumSum += arr[i];

            if (cumSum % 2 == 0) {
                result = (result + oddSumCount) % MOD;
                evenSumCount++;
            } else {
                result = (result + evenSumCount) % MOD;
                oddSumCount++;
            }
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
