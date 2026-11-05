class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            auto idx = lower_bound(arr2.begin(), arr2.end(), arr1[i]);

            if ((idx == arr2.end() || *idx - arr1[i] > d) &&
                (idx == arr2.begin() || arr1[i] - *(idx - 1) > d)) {
                ans++;
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
