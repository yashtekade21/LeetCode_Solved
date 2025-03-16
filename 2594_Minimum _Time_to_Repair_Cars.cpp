class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int maxTime = *max_element(ranks.begin(), ranks.end());

        long long l = 1, r = maxTime * pow(cars, 2);
        long long minTime;
        while (l <= r) {
            long long mid = (l + r) / 2;

            if (checkCarRepairTime(ranks, cars, mid)) {
                minTime = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return minTime;
    }

private:
    bool checkCarRepairTime(vector<int>& ranks, int cars, long long time) {
        int n = ranks.size();
        long long totalCars = 0;

        for (int i = 0; i < n; i++) {
            totalCars += sqrt(time / ranks[i]);
        }

        if (totalCars >= cars)
            return true;
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
