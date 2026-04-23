class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, long long> idxSum, numFreq;

        for (int i = 0; i < n; i++) {
            if (idxSum.count(nums[i]) && numFreq.count(nums[i])) {
                long long freq = numFreq[nums[i]], sum = idxSum[nums[i]];
                ans[i] = (freq * i) - sum;
            }

            idxSum[nums[i]] += i;
            numFreq[nums[i]]++;
        }

        idxSum.clear();
        numFreq.clear();

        for (int i = n - 1; i >= 0; i--) {
            if (idxSum.count(nums[i]) && numFreq.count(nums[i])) {
                long long freq = numFreq[nums[i]], sum = idxSum[nums[i]];
                ans[i] += sum - (freq * i);
            }

            idxSum[nums[i]] += i;
            numFreq[nums[i]]++;
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
