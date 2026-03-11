class Solution {
public:
    int bitwiseComplement(int n) {
        int allSet = 1;

        while(allSet < n){
            allSet <<= 1;
            allSet += 1;
        }
        return n ^ allSet;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
