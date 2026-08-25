class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (auto& num : nums)
            st.insert(num);

        int i = 1;
        while (true) {
            int multiple = k * i;
            if (st.find(multiple) == st.end())
                break;
            i++;
        }
        return i * k;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
