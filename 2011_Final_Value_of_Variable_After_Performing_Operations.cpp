class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        int n = operations.size();

        for (int i = 0; i < n; i++) {
            string op = operations[i];
            if (op == "++X" || op == "X++")
                ans++;
            else
                ans--;
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
