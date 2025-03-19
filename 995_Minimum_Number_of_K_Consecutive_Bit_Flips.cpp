class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flipsNeeded = 0, totalFlips = 0;
        vector<bool> flipsDone(n, false);

        for (int i = 0; i < n; i++) {
            if (i >= k && flipsDone[i - k]) {
                flipsNeeded--;
            }

            if (flipsNeeded % 2 == nums[i]) {
                if (i > n - k)
                    return -1;

                flipsNeeded++;
                totalFlips++;
                flipsDone[i] = true;
            }
        }
        return totalFlips;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
