class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int totalSeats = 0;
        for (auto& place : corridor)
            totalSeats += (place == 'S') ? 1 : 0;

        if (totalSeats % 2 != 0 || totalSeats == 0)
            return 0;

        int n = corridor.size();
        vector<pair<int, int>> sections;
        long long ans = 1;

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                int j = i + 1;
                while (j < n) {
                    if (corridor[j] == 'S') {
                        sections.push_back({i, j});
                        break;
                    }
                    j++;
                }
                i = j;
            }
        }

        int sec1Idx = -1, sec2Idx = -1;
        for (auto& secIdx : sections) {
            cout << "{" << secIdx.first << "," << secIdx.second << "}" << endl;
            if (sec1Idx == -1)
                sec1Idx = secIdx.second;
            else if (sec2Idx == -1)
                sec2Idx = secIdx.first;

            if (sec1Idx != -1 && sec2Idx != -1) {
                int diff = sec2Idx - sec1Idx;
                ans = (ans * diff) % MOD;
                sec1Idx = secIdx.second;
                sec2Idx = -1;
            }
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
