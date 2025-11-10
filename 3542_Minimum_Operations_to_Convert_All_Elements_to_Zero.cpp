class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i])
                st.pop();

            if (nums[i] == 0)
                continue;

            if (st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
                ans++;
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
