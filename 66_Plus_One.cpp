class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.begin(), digits.end());

        bool carry = true;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (!carry)
                continue;

            if (ans[i] != 9) {
                ans[i]++;
                carry = false;
            } else
                ans[i] = 0;
        }
        if (carry)
            ans.insert(ans.begin(), 1);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
