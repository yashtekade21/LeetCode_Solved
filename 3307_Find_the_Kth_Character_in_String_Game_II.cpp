class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1)
            return 'a';

        int n = operations.size();
        long long len = 1, op = -1, reducedK = -1;

        for (int i = 0; i < n; i++) {
            len *= 2;

            if (len >= k) {
                op = operations[i];
                reducedK = k - len / 2;
                break;
            }
        }

        char ans = kthCharacter(reducedK, operations);

        if (op == 1)
            ans = ((ans - 'a' + 1) % 26) + 'a';
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
