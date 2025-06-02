class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candyL(n, 1), candyR(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && ratings[i - 1] < ratings[i])
                candyL[i] = max(candyL[i], candyL[i - 1] + 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && ratings[i + 1] < ratings[i])
                candyR[i] = max(candyR[i], candyR[i + 1] + 1);
        }

        for (int i = 0; i < n; i++)
            ans += max(candyL[i], candyR[i]);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
