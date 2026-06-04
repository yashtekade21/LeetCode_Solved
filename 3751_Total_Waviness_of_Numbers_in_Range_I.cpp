class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = max(100, num1); num <= num2; num++)
            ans += find(num);

        return ans;
    }

private:
    int find(int num) {
        int w = 0;
        int r = num % 10;
        num /= 10;
        int m = num % 10;
        num /= 10;

        while (num) {
            int l = num % 10;

            if (m > r && m > l)
                w++;
            else if (m < r && m < l)
                w++;

            r = m;
            m = l;
            num /= 10;
        }
        return w;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
