class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end()),
                  high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (CalcCap(weights, mid) > days)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

private:
    int CalcCap(vector<int>& arr, int cap) {
        long long load = 0;
        int days = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (load + arr[i] > cap) {
                days++;
                load = arr[i];
            } else
                load += arr[i];
        }
        return days;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
