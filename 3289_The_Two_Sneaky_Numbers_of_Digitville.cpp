class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> freq(101, 0);
        vector<int> ans;

        for (auto& num : nums)
            freq[num]++;

        for (int num = 0; num <= 100; num++) {
            if (freq[num] > 1) {
                ans.emplace_back(num);
                if (ans.size() >= 2)
                    break;
            }
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
