class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        int prev_x = -1;
        int prev_y = -1;
        int ans = 0;

        for (auto& interval : intervals) {
            int cur_x = interval[0];
            int cur_y = interval[1];

            bool x_overlap = prev_x >= cur_x;
            bool y_overlap = prev_y >= cur_x;

            if (x_overlap && y_overlap)
                continue;
            else if (y_overlap) {
                ans++;
                prev_x = prev_y;
                prev_y = cur_y;
            } else {
                ans += 2;
                prev_x = cur_y - 1;
                prev_y = cur_y;
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
