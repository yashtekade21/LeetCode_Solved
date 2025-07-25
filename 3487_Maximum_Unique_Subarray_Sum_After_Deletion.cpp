class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        int maxNeg = INT_MIN;

        unordered_set<int> st;

        for (auto& num : nums) {
            if (num <= 0)
                maxNeg = max(maxNeg, num);
            else if (st.find(num) == st.end()) {
                ans += num;
                st.insert(num);
            }
        }

        return ans == 0 ? maxNeg : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
