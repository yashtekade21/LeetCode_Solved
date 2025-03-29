class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlti = 0;
        int n = gain.size();
        int prefAlt = 0;

        for (int i = 0; i < n; i++) {
            prefAlt += gain[i];
            maxAlti = max(maxAlti, prefAlt);
        }
        return maxAlti;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
