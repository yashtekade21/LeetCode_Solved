class Solution {
public:
    int binaryGap(int n) {
        int curBitPos = 0, prevBitPos = -1;
        int ans = 0;
        while (n != 0) {
            int bit = n & 1;
            if (bit == 1) {
                if (prevBitPos != -1)
                    ans = max(ans, abs(prevBitPos - curBitPos));

                prevBitPos = curBitPos;
            }

            curBitPos++;
            n >>= 1;
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
