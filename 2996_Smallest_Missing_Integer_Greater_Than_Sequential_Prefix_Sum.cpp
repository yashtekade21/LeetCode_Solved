class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums), end(nums));

        int ans = nums[0];
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1)
                ans += nums[j];
            else
                break;
        }

        while (st.count(ans))
            ans++;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
