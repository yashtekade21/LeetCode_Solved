class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int k = strs[0].size();
        int ans = 0;
        vector<bool> inOrder(n, false);

        for (int i = 0; i < k; i++) {
            char cPrev = strs[0][i];
            bool deleted = false;
            for (int j = 1; j < n; j++) {
                char cNext = strs[j][i];
                if (!inOrder[j] && cPrev > cNext) {
                    deleted = true;
                    ans++;
                    break;
                }
                cPrev = cNext;
            }
            
            if (deleted)
                continue;

            for (int l = 1; l < n; l++) {
                if (!inOrder[l] && strs[l - 1][i] < strs[l][i])
                    inOrder[l] = true;
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
