class Solution {
public:
    int n;
    int countCollisions(string directions) {
        n = directions.length();
        int start = 0;
        int end = n - 1;

        while (start < n && directions[start] == 'L')
            start++;

        while (end >= 0 && directions[end] == 'R')
            end--;

        int ans = 0;
        while (start <= end) {
            if (directions[start] != 'S') {
                ans++;
            }
            start++;
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
