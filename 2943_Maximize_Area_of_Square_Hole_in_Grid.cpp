class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxLen = 1, maxWid = 1;
        int curLen = 1;
        for (int i = 1; i < h; i++) {
            if (hBars[i] == hBars[i - 1] + 1)
                curLen++;
            else
                curLen = 1;

            maxLen = max(maxLen, curLen);
        }

        int curWid = 1;
        for (int i = 1; i < v; i++) {
            if (vBars[i] == vBars[i - 1] + 1)
                curWid++;
            else
                curWid = 1;

            maxWid = max(maxWid, curWid);
        }

        int side = min(maxLen, maxWid) + 1;
        return side * side;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
