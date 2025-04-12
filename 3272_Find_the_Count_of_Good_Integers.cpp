class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;

        long long ans = 0;
        int leftSize = (n + 1) / 2;
        int start = power(10, leftSize - 1);
        int end = power(10, leftSize) - 1;

        for (int num = start; num <= end; num++) {
            string leftStr = to_string(num);
            string rightStr = "";

            if (n % 2 == 0) {
                rightStr = leftStr;
                reverse(rightStr.begin(), rightStr.end());
            } else {
                rightStr = leftStr.substr(0, leftSize - 1);
                reverse(rightStr.begin(), rightStr.end());
            }
            string kNum = leftStr + rightStr;

            long long number = stoll(kNum);
            if (number % k != 0)
                continue;

            sort(kNum.begin(), kNum.end());
            st.insert(kNum);
        }

        for (auto& kNum : st) {
            vector<int> mp(10, 0);
            for (auto& ch : kNum) {
                int digit = ch - '0';
                mp[digit]++;
            }

            int totalDigits = kNum.length();
            int zeros = mp[0];
            int nonZeros = totalDigits - zeros;

            long long comb = (nonZeros * fact(totalDigits - 1));
            for (auto& freq : mp)
                comb /= fact(freq);

            ans += comb;
        }
        return ans;
    }

private:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long halfPower = power(base, exp / 2);
        if (exp % 2 == 0)
            return halfPower * halfPower;
        return base * halfPower * halfPower;
    }

    long long fact(int num) {
        vector<long long> factorial(num + 1);
        factorial[0] = 1;

        for (int i = 1; i <= num; i++)
            factorial[i] = i * factorial[i - 1];

        return factorial[num];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
