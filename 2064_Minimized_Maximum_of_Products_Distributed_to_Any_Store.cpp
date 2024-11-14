class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (can_distribute(mid, quantities, n)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

private:
    bool can_distribute(int x, vector<int>& arr, int n) {
        int stores_needed = 0;
        for (auto i : arr)
            stores_needed += ceil((float)i / (float)x);

        return stores_needed <= n;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
