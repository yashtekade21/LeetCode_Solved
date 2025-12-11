class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const noexcept {
            return ((size_t)p.first << 32) ^ (size_t)p.second;
        }
    };
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        unordered_map<int, set<pair<int, int>>> mpX, mpY;
        unordered_set<pair<int, int>, PairHash> st;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            mpX[x].insert({x, y});
            mpY[y].insert({x, y});
        }

        for (auto& [key, grps] : mpX) {
            if (grps.size() <= 2)
                continue;

            auto it = grps.begin();
            ++it;

            auto last = grps.end();
            --last;

            for (; it != last; it++) {
                pair<int, int> building = *it;
                st.insert(building);
            }
        }

        for (auto& [key, grps] : mpY) {
            if (grps.size() <= 2)
                continue;

            auto it = grps.begin();
            ++it;

            auto last = grps.end();
            --last;

            for (; it != last; it++) {
                pair<int, int> building = *it;
                if (st.count(building) > 0)
                    ans++;

                st.insert(building);
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
