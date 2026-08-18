class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        unordered_map<int, int> mp;
        unordered_set<int> st;
        while (j < n) {
            if (j - i + 1 == k) {
                for (int l = i; l <= j; l++)
                    st.insert(nums[l]);

                for (int x : st)
                    mp[x]++;

                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        int ans = -1;
        for (auto [num, count] : mp) {
            if (count == 1 && num > ans) {
                ans = num;
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
