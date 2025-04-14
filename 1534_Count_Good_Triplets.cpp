class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int x = abs(arr[i] - arr[j]);
                if (x <= a) {
                    for (int k = j + 1; k < n; k++) {
                        int y = abs(arr[j] - arr[k]);
                        int z = abs(arr[i] - arr[k]);
                        if (y <= b && z <= c)
                            ans++;
                    }
                }
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
