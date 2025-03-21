class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        for (auto& num : nums) {
            if (num % 2 == 0)
                mp[num]++;
        }

        if (!mp.empty()) {
            int maxFreq = INT_MIN;
            int evenNum;
            for (auto& [num, freq] : mp) {
                if (freq > maxFreq) {
                    maxFreq = freq;
                    evenNum = num;
                }
            }
            return evenNum;
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
