class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int num = n, prod = 1;

            while (num != 0) {
                int lastDig = num % 10;
                prod *= lastDig;
                num /= 10;
            }

            if (prod % t == 0)
                return n;

            n++;
        }
        return 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
