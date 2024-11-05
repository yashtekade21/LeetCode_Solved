class Solution {
public:
    int hammingDistance(int x, int y) {
        int bin = x ^ y;
        int cnt = 0;

        while (bin != 0) {
            if (bin&1 == 1)
                cnt++;
            bin >>= 1;
        }

        return cnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
