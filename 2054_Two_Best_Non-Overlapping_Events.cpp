class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        dp.resize(100001, vector<int>(3, -1));
        sort(events.begin(), events.end());

        return solve(events, 0, 0);
    }

private:
    int solve(vector<vector<int>>& events, int i, int cnt) {
        if (cnt == 2 || i >= n)
            return 0;

        if (dp[i][cnt] != -1)
            return dp[i][cnt];

        int nextIndex = bs(events, events[i][1]);

        int attend = events[i][2] + solve(events, nextIndex, cnt + 1);

        int not_attend = solve(events, i + 1, cnt);

        return dp[i][cnt] = max(attend, not_attend);
    }

    int bs(vector<vector<int>>& events, int endTime) {
        int l = 0, r = n - 1;
        int ind = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                ind = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ind;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
