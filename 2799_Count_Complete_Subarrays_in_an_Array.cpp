class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for (int& num : nums)
            st.insert(num);

        int distNums = st.size();
        st.clear();

        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() == distNums) {
                ans += (n - j);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
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
