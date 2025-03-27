class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        pair<int, int> maxNumFreq = {0, 0};
        for (auto& num : nums) {
            freq[num]++;
            if (freq[num] > maxNumFreq.second) {
                maxNumFreq.first = num;
                maxNumFreq.second = freq[num];
            }
        }

        int j = n - 1;
        int f1 = 0, f2 = 0;
        int ans = n;
        while (j > 0) {
            if (nums[j] == maxNumFreq.first) {
                f2++;
            }
            f1 = maxNumFreq.second - f2;

            if (f1 > j / 2 && f2 > (n - j) / 2) {
                ans = min(j - 1, ans);
            }
            j--;
        }
        return (ans == n) ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
      return 0;
}();
