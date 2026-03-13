class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTimeReq = *max_element(workerTimes.begin(), workerTimes.end());

        long long l = 1, r = (long long)maxTimeReq * mountainHeight *
                             (mountainHeight + 1) / 2;
        long long ans = 0;

        while (l <= r) {
            long long m = (l + r) / 2;

            if (check(m, mountainHeight, workerTimes)) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return ans;
    }

private:
    bool check(long long time, int mountainHeight, vector<int>& workerTimes) {
        long long height = 0;
        for (auto& t : workerTimes) {
            height += (long long)(sqrt(2.0 * time / t + 0.25) - 0.5);

            if (height >= mountainHeight)
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
