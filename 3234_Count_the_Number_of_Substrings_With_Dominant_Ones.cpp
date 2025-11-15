class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        vector<int> cumSumOne(n, 0);
        cumSumOne[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
            cumSumOne[i] = cumSumOne[i - 1] + s[i] - '0';

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cntOne = cumSumOne[j] - ((i > 0) ? cumSumOne[i - 1] : 0);
                int cntZero = (j - i + 1) - cntOne;

                if ((cntZero * cntZero) == cntOne) {
                    ans++;
                } else if ((cntZero * cntZero) > cntOne) {
                    int skipIndices = (cntZero * cntZero) - cntOne;
                    j += skipIndices - 1; // increasing in for loop so -1
                } else {
                    ans++;
                    int skipIndices = sqrt(cntOne) - cntZero;
                    int j_next = j + skipIndices;

                    if (j_next >= n) {
                        ans += (n - j - 1);
                        break;
                    } else {
                        ans += skipIndices;
                    }
                    j = j_next;
                }
            }
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
