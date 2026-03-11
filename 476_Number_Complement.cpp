class Solution {
public:
    int findComplement(int num) {
        int allSet = 1;

        while (allSet < num) {
            allSet <<= 1;
            allSet += 1;
        }

        return num ^ allSet;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
