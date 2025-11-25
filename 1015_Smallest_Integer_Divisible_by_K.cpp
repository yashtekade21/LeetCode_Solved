class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long num = 1;
        int ans = 1;
        
        while (num % k != 0 && ans <= k) {
            int rem = num % k;
            num = rem * 10 + 1;
            ans++;
        }

        return (ans > k) ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
