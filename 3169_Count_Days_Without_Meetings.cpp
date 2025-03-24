class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<vector<int>> meetDays;
        int i = 0;
        while (i < n) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            while (i + 1 < n && end >= meetings[i + 1][0]) {
                end = max(end, meetings[i+1][1]);
                i++;
            }
            meetDays.push_back({start, end});
            i++;
        }

        int totalMeetDays = 0;
        for (auto& days : meetDays) {
            // cout<<days[0]<<" "<<days[1]<<endl;
            totalMeetDays += (days[1] - days[0] + 1);
        }
        return days - totalMeetDays;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
