class Solution {
public:
    int n;
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();

        vector<long long> diffArr(n, 0);

        for (int i = 0; i < n; i++) {
            diffArr[max(0, i - r)] += stations[i];

            if (i + r + 1 < n)
                diffArr[i + r + 1] -= stations[i];
        }

        long long low = *min_element(stations.begin(), stations.end());
        long long high = accumulate(stations.begin(), stations.end(), 0LL) + k;

        long long ans = 0;

        while (low <= high) {
            long long mid = (high + low) / 2;

            if (valid(mid, diffArr, r, k)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }

private:
    bool valid(long long mid, vector<long long>& diffArr, int r, int k) {
        vector<long long> tempDiffArr = diffArr;

        long long cumSum = 0;

        for (int i = 0; i < n; i++) {
            cumSum += tempDiffArr[i];

            if (cumSum < mid) {
                long long require = mid - cumSum;
                if (require > k)
                    return false;

                k -= require;
                cumSum += require;

                if (i + 2 * r + 1 < n)
                    tempDiffArr[i + 2 * r + 1] -= require;
            }
        }

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
