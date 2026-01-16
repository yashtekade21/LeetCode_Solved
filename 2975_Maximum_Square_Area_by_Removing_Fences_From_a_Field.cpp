class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        int v = vFences.size(), h = hFences.size();
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> widths;

        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) {
                int wid = vFences[j] - vFences[i];
                widths.insert(wid);
            }
        }

        int maxSide = 0;
        for (int i = 0; i < h; i++) {
            for (int j = i + 1; j < h; j++) {
                int hei = hFences[j] - hFences[i];
                if (widths.find(hei) != widths.end()) {
                    maxSide = max(maxSide, hei);
                }
            }
        }

        return maxSide != 0 ? (1LL * maxSide * maxSide) % MOD : -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
