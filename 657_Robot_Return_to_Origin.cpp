class Solution {
public:
    bool judgeCircle(string moves) {
        int udMag = 0, lrMag = 0;

        for (auto& move : moves) {
            if (move == 'U' || move == 'D')
                udMag += (move == 'U' ? 1 : -1);
            else
                lrMag += (move == 'R' ? 1 : -1);
        }

        if (udMag != 0 || lrMag != 0)
            return false;

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
