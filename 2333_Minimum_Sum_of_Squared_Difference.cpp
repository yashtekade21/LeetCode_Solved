class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i)
            diff[i] = abs(nums1[i] - nums2[i]);

        int maxDiff = *max_element(diff.begin(), diff.end());
        vector<int> cntDiff(maxDiff + 1, 0);
        for (int d : diff)
            cntDiff[d]++;

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps = min(cntDiff[currDiff], K);

            cntDiff[currDiff] -= countOps;
            cntDiff[currDiff - 1] += countOps;
            K -= countOps;
        }

        long long ans = 0;
        for (long long d = 1; d <= maxDiff; ++d)
            ans += cntDiff[d] * d * d;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
