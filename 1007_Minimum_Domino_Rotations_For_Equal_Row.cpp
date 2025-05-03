class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = tops.size() + 1;

        for (int num = 1; num <= 6; num++) {
            int reqSwaps = solve(tops, bottoms, num);
            if (reqSwaps != -1)
                ans = min(ans, reqSwaps);
        }
        return (ans == tops.size() + 1) ? -1 : ans;
    }

private:
    int solve(vector<int>& tops, vector<int>& bottoms, int num) {
        int topSwaps = 0, bottomSwaps = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            if (tops[i] != num && bottoms[i] != num)
                return -1;
            else if (tops[i] != num)
                topSwaps++;
            else if (bottoms[i] != num)
                bottomSwaps++;
        }
        return min(topSwaps, bottomSwaps);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
