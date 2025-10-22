class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diffMp;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            diffMp[l]++;
            diffMp[r + 1]--;

            diffMp[nums[i]] += 0; // to consider nums element also as a target
        }

        int ans = 1;
        int cumSum = 0;
        for (auto it = diffMp.begin(); it != diffMp.end(); it++) {
            int target = it->first;
            it->second += cumSum;

            int targetFreq = freq[target];
            int needOperation = it->second - targetFreq;

            int maxPossibleFreq = min(needOperation, numOperations);

            ans = max(ans, targetFreq + maxPossibleFreq);

            cumSum = it->second;
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
