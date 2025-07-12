class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int fP = firstPlayer, sP = secondPlayer;

        if (fP == n - sP + 1)
            return {1, 1};

        if (fP > n - sP + 1) {
            int temp = n - fP + 1;
            fP = n - sP + 1;
            sP = temp;
        }

        int minRound = n, maxRound = 1;
        int nxtRoundPlayers = (n + 1) / 2;

        if (sP <= nxtRoundPlayers) { // both player are on same side
            int leftPlayers = fP - 1;
            int midPlayers = sP - fP - 1;

            for (int lP = 0; lP <= leftPlayers; lP++) {
                for (int mP = 0; mP <= midPlayers; mP++) {
                    int p1 = lP + 1;
                    int p2 = p1 + mP + 1;
                    vector<int> tempAns =
                        earliestAndLatest(nxtRoundPlayers, p1, p2);

                    minRound = min(minRound, tempAns[0] + 1);
                    maxRound = max(maxRound, tempAns[1] + 1);
                }
            }
        } else { // both on diff side
            int oppOfsP = n - sP + 1;
            int leftPlayers = fP - 1;
            int midPlayers = oppOfsP - fP - 1;
            int remMidPlayers = sP - oppOfsP - 1;

            for (int lP = 0; lP <= leftPlayers; lP++) {
                for (int mP = 0; mP <= midPlayers; mP++) {
                    int p1 = lP + 1;
                    int p2 = p1 + mP + (remMidPlayers + 1) / 2 + 1;

                    vector<int> tempAns =
                        earliestAndLatest(nxtRoundPlayers, p1, p2);

                    minRound = min(minRound, tempAns[0] + 1);
                    maxRound = max(maxRound, tempAns[1] + 1);
                }
            }
        }
        return {minRound, maxRound};
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
