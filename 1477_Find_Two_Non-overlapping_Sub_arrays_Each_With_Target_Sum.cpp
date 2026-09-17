class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0, currSum = 0, bestMinLen = INT_MAX, ans = INT_MAX;
        vector<int> minBestLenTillIdx(n, INT_MAX);

        while (j < n) {
            currSum += arr[j];

            while (i < j && currSum > target)
                currSum -= arr[i++];

            if (currSum == target) {
                int len = j - i + 1;

                if (i > 0 && minBestLenTillIdx[i - 1] != INT_MAX)
                    ans = min(ans, len + minBestLenTillIdx[i - 1]);

                bestMinLen = min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
