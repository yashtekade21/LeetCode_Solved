class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int ans = 0;
        int curr = 0, prev = 0;

        for (int i = 0; i < n; i++) {
            curr = target[i];

            if (abs(curr) > abs(prev)) 
                ans += abs(curr - prev);

            prev = curr;
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
