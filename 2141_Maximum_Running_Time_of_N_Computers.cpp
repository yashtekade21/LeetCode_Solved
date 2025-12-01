class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        return binSearch(n, batteries);
    }

private:
    long long binSearch(int n, vector<int>& batteries) {
        long long total = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long ans = 0;
        long long l = *min_element(batteries.begin(), batteries.end());
        long long r = total / n;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (possible(n, batteries, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    bool possible(int n, vector<int>& batteries, long long time) {
        long long totalMins = n * time;

        for (long long b : batteries) {
            totalMins -= min(b, time);

            if (totalMins <= 0)
                return true;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
