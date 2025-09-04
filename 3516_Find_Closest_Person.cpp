class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1_p3 = abs(x-z);
        int p2_p3 = abs(y-z);

        return (p1_p3 == p2_p3) ? 0 : (p1_p3 < p2_p3) ? 1 : 2;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
