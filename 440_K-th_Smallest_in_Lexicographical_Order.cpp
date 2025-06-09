class Solution {
public:
    int findKthNumber(int n, int k) {
        int num = 1;
        k--;

        while (k > 0) {
            int siblings = cntSiblings(num, num + 1, n);
            if (siblings <= k) {
                num++;
                k -= siblings;
            } else {
                num *= 10;
                k--;
            }
        }

        return num;
    }

private:
    int cntSiblings(long long num, long long sib, int n) {
        int count = 0;

        while (num <= n) {
            count += (sib - num);
            num *= 10;
            sib = min(sib * 10, static_cast<long long>(n + 1));
        }
        return count;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
