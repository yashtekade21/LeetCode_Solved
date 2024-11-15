class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n - 1;

        while (r > 0 && arr[r - 1] <= arr[r])
            r--;

        int ans = r;

        int l = 0;
        while (l < r) {
            while (r < n && arr[l] > arr[r])
                r++;
            ans = min(ans, r - l - 1);
            if (arr[l] > arr[l + 1])
                break;

            l++;
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
