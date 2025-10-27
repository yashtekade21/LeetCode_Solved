class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].length();
        vector<int> devices;

        for (int i = 0; i < n; i++) {
            string floor = bank[i];
            int totalDevices = 0;
            for (int j = 0; j < m; j++) {
                totalDevices += floor[j] - '0';
            }
            if (totalDevices)
                devices.emplace_back(totalDevices);
        }

        int ans = 0;
        for (int i = 0; i + 1 < devices.size(); i++)
            ans += (devices[i] * devices[i + 1]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
