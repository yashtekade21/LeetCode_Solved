class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0, j = 0;
        int ans = 0;

        int tempSum = 0;
        while (j < n) {
            st.insert(nums[j]);
            tempSum += nums[j];

            if (j - i + 1 == st.size())
                ans = max(ans, tempSum);

            while (j - i + 1 != st.size()) {
                if (nums[j] != nums[i])
                    st.erase(nums[i]);
                tempSum -= nums[i];
                i++;
            }
            j++;
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
