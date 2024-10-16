class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int maxLen = a + b + c;
        int cnt_a = 0, cnt_b = 0, cnt_c = 0;
        string ans = "";

        for (int i = 0; i < maxLen; i++) {
            if ((a >= b && a >= c && cnt_a != 2) || (cnt_b == 2 && a > 0) ||
                (cnt_c == 2 && a > 0)) {
                ans += 'a';
                a--;
                cnt_a++;
                cnt_b = cnt_c = 0;
            } else if ((b >= a && b >= c && cnt_b != 2) ||
                       (cnt_a == 2 && b > 0) || (cnt_c == 2 && b > 0)) {
                ans += 'b';
                b--;
                cnt_b++;
                cnt_a = cnt_c = 0;
            } else if ((c >= a && c >= b && cnt_c != 2) ||
                       (cnt_a == 2 && c > 0) || (cnt_b == 2 && c > 0)) {
                ans += 'c';
                c--;
                cnt_c++;
                cnt_a = cnt_b = 0;
            }
            else
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
