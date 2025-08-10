class Solution {
public:
    unordered_set<string> st;
    bool reorderedPowerOf2(int n) {
        if (st.empty())
            preComputePower();
        string num = to_string(n);
        sort(num.begin(), num.end());

        return st.count(num) > 0;
    }

private:
    void preComputePower() {
        for (int i = 0; i < 30; i++) {
            string num = to_string(1 << i);
            sort(num.begin(), num.end());
            st.insert(num);
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
