class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> inactiveZeros;

        int ones = count(begin(s), end(s), '1');
        int n = s.length();

        int r = 0;
        while (r < n) {
            if (s[r] == '0') {
                int l = r;

                while (r < n && s[r] == '0')
                    r++;

                inactiveZeros.push_back(r - l);
            } else {
                r++;
            }
        }

        int ans = 0;
        for (int i = 1; i < inactiveZeros.size(); i++) {
            ans = max(ans, inactiveZeros[i] + inactiveZeros[i - 1]);
        }
        ans += ones;
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
