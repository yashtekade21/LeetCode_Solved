class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](auto& vec1, auto& vec2) {
            if (vec1[0] != vec2[0])
                return vec1[0] < vec2[0];
            return vec1[1] > vec2[1];
        };
        sort(intervals.begin(), intervals.end(), lambda);
        stack<pair<int, int>> st;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int a = intervals[i][0], b = intervals[i][1];
            int c = -1, d = -1;

            if (!st.empty()) {
                c = st.top().first;
                d = st.top().second;
            }

            if (!st.empty() && c <= a && b <= d)
                cnt++;
            else
                st.push({a, b});
        }
        return n - cnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
