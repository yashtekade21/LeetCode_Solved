class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n) {
            if (bits[i] == 1 && i + 1 < n) {
                i++;
            } else if (i == n - 1) {
                break;
            }
            i++;
        }
        return (i == n - 1) ? true : false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
