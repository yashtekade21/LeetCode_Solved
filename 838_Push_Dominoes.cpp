class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> leftCloseR(n, -1), rightCloseL(n, -1);

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                leftCloseR[i] = i;
            } else if (dominoes[i] == '.' && i - 1 >= 0 &&
                       leftCloseR[i - 1] != -1) {
                leftCloseR[i] = leftCloseR[i - 1];
            }

            if (dominoes[n - i - 1] == 'L') {
                rightCloseL[n - i - 1] = n - i - 1;
            } else if (dominoes[n - i - 1] == '.' && n - i < n &&
                       rightCloseL[n - i] != -1) {
                rightCloseL[n - i - 1] = rightCloseL[n - i];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << leftCloseR[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << rightCloseL[i] << " ";
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (leftCloseR[i] == rightCloseL[i]) {
                ans += '.';
            } else if (leftCloseR[i] == -1) {
                ans += 'L';
            } else if (rightCloseL[i] == -1) {
                ans += 'R';
            } else {
                int leftCloseRDist = abs(i - leftCloseR[i]);
                int rightCloseLDist = abs(i - rightCloseL[i]);

                if (leftCloseRDist == rightCloseLDist) {
                    ans += '.';
                } else if (leftCloseRDist > rightCloseLDist) {
                    ans += 'L';
                } else {
                    ans += 'R';
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
