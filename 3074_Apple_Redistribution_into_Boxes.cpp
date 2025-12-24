class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        int ans = 0;

        for (auto& cap : capacity) {
            totalApples -= cap;
            ans++;
            if (totalApples <= 0)
                break;
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
