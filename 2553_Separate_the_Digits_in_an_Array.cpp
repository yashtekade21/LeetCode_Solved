class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (auto& num : nums) {
            int temp = num;
            vector<int> digspilt;
            while (temp != 0) {
                int lastDigit = temp % 10;
                temp /= 10;
                digspilt.emplace_back(lastDigit);
            }
            reverse(digspilt.begin(), digspilt.end());
            ans.insert(ans.end(), digspilt.begin(), digspilt.end());
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
