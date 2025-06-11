class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.length();
        int ans = INT_MIN;

        for (char num1 = '0'; num1 <= '4'; num1++) {
            for (char num2 = '0'; num2 <= '4'; num2++) {
                if (num1 == num2)
                    continue;

                vector<int> minValof_num1_num2(4, INT_MAX);

                int cnt_num1 = 0, cnt_num2 = 0;
                int prev_cnt_num1 = 0, prev_cnt_num2 = 0;

                int i = 0, j = 0;

                while (j < n) {
                    cnt_num1 += (s[j] == num1) ? 1 : 0;
                    cnt_num2 += (s[j] == num2) ? 1 : 0;

                    while (j - i + 1 >= k && cnt_num1 - prev_cnt_num1 >= 1 &&
                           cnt_num2 - prev_cnt_num2 >= 2) {
                        int prevParity =
                            getParity(prev_cnt_num1, prev_cnt_num2);
                        minValof_num1_num2[prevParity] =
                            min(minValof_num1_num2[prevParity],
                                prev_cnt_num1 - prev_cnt_num2);

                        prev_cnt_num1 += s[i] == num1 ? 1 : 0;
                        prev_cnt_num2 += s[i] == num2 ? 1 : 0;
                        i++;
                    }

                    int nextParity = getParity(cnt_num1, cnt_num2);
                    int bestPrevParity = nextParity ^ 2;  // mathematics to get best prevMinValParity
                    int minDiffVal = minValof_num1_num2[bestPrevParity];

                    ans = minDiffVal == INT_MAX
                              ? ans
                              : max(ans, (cnt_num1 - cnt_num2) - minDiffVal);

                    j++;
                }
            }
        }
        return ans;
    }

private:
    int getParity(int cnt_num1, int cnt_num2) {
        int parity_num1 = cnt_num1 % 2;
        int parity_num2 = cnt_num2 % 2;

        if (parity_num1 == 0 && parity_num2 == 0)
            return 0; // even even case
        else if (parity_num1 == 0 && parity_num2 == 1)
            return 1; // even odd
        else if (parity_num1 == 1 && parity_num2 == 0)
            return 2; // odd even

        return 3; // odd odd
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
