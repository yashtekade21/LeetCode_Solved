class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());

        int l = 1, r = maxCandies;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            long long childs = k;
            for (int& candy : candies) {
                childs -= (long long)(candy / mid);
            }

            if (childs <= 0) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
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
