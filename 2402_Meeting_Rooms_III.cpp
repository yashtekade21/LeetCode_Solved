class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int m = meetings.size();
        vector<int> roomsUsedCount(n, 0);

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for (int r = 0; r < n; r++)
            availableRooms.push(r);

        for (auto& meet : meetings) {
            int startTime = meet[0], endTime = meet[1];

            while (!usedRooms.empty() && usedRooms.top().first <= startTime) {
                int r = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(r);
            }

            if (!availableRooms.empty()) {
                int r = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({endTime, r});
                roomsUsedCount[r]++;
            } else {
                int r = usedRooms.top().second;
                long long end = usedRooms.top().first;

                usedRooms.pop();
                usedRooms.push({end + (endTime - startTime), r});
                roomsUsedCount[r]++;
            }
        }

        int ans = -1, maxRoomUse = 0;
        for (int r = n - 1; r >= 0; r--) {
            if (roomsUsedCount[r] >= maxRoomUse) {
                ans = r;
                maxRoomUse = roomsUsedCount[r];
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
