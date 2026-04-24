class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, udsr = 0;

        for (auto& move : moves) {
            if (move == 'L')
                l++;
            else if (move == 'R')
                r++;
            else
                udsr++;
        }

        if (l > r)
            return l + udsr - r;
        else if (l < r)
            return r + udsr - l;

        return l + udsr - r;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
