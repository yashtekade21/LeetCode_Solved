class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int k = strs[0].size();
        int ans = 0;

        for (int i = 0; i < k; i++) {
            char cPrev = strs[0][i];
            for (int j = 1; j < n; j++) {
                char cNext = strs[j][i];
                if (cPrev > cNext) {
                    ans++;
                    break;
                }
                cPrev = cNext;
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
