class Solution {
public:
    bool checkPowersOfThree(int n) {
        string num = "";

        int N = n;
        while (N > 0) {
            int rem = N % 3;
            num = to_string(rem) + num;
            N /= 3;
        }

        for (int i = 0; i < num.length(); i++) {
            if ((num[i] - '0') >= 2)
                return false;
        }

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
