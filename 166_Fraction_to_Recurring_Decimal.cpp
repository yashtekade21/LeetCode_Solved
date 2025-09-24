class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        unordered_map<int, int> mp;

        string ans = "";
        if ((long long)numerator * (long long)denominator < 0)
            ans += "-";

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        long long quotient = absNumerator / absDenominator;
        ans += to_string(quotient);

        long long remainder = absNumerator % absDenominator;
        if (remainder == 0)
            return ans;
        ans += ".";

        while (remainder != 0) {
            if (mp.find(remainder) != mp.end()) {
                ans.insert(mp[remainder], "(");
                ans += ")";
                break;
            }

            mp[remainder] = ans.length();
            remainder *= 10;

            long long digit = remainder / absDenominator;
            ans += to_string(digit);
            remainder = remainder % absDenominator;
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
