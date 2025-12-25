class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        int i = 0;

        while (i < n && k != 0) {
            ans += (happiness[i] - i) > 0 ? happiness[i] - i : 0;
            i++;
            k--;
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
