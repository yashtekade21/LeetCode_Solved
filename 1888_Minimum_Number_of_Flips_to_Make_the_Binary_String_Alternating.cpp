class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        string sNew = s + s;

        // Possible final states
        // 10101010... OR 01010101...

        string s1Final, s2Final;

        for (int i = 0; i < 2 * n; i++) {
            s1Final += (i % 2 ? '1' : '0');
            s2Final += (i % 2 ? '0' : '1');
        }

        int ans = INT_MAX;
        int flip1Cnt = 0, flip2Cnt = 0;
        int i = 0, j = 0;

        while (j < 2 * n) {
            if (sNew[j] != s1Final[j])
                flip1Cnt++;

            if (sNew[j] != s2Final[j])
                flip2Cnt++;

            if (j - i + 1 > n) {
                if (sNew[i] != s1Final[i])
                    flip1Cnt--;

                if (sNew[i] != s2Final[i])
                    flip2Cnt--;

                i++;
            }

            if (j - i + 1 == n)
                ans = min(ans, min(flip1Cnt, flip2Cnt));
            j++;
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
