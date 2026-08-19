class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto& reservedSeat : reservedSeats) {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }

        int ans = (n - mp.size()) * 2;

        for (auto& [row, bookedSeats] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool s1 = isAvailable(2) && isAvailable(3) &&
                      isAvailable(4) & isAvailable(5);
            bool s2 = isAvailable(4) && isAvailable(5) &&
                      isAvailable(6) & isAvailable(7);
            bool s3 = isAvailable(6) && isAvailable(7) &&
                      isAvailable(8) & isAvailable(9);

            if (s1 && s3)
                ans += 2;
            else if (s1 || s2 || s3)
                ans += 1;
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
