class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;

        unordered_map<int, int> freq;
        for (auto& num : nums) {
            freq[num]++;

            if (freq[num] == n)
                return num;
        }
        return 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
