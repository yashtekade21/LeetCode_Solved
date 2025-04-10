class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string start_str = to_string(start - 1);
        string finish_str = to_string(finish);

        return findPowerful(finish_str, limit, s) -
               findPowerful(start_str, limit, s);
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
    long long findPowerful(string& str, int limit, string& suffix) {
        long long strLen = str.length(), sufLen = suffix.length();
        if (strLen < sufLen)
            return 0;

        long long totalCnt = 0;
        string strSuffix = str.substr(strLen - sufLen);
        long long remLen = strLen - sufLen;

        for (int i = 0; i < remLen; i++) {
            int curDigit = str[i] - '0';

            if (curDigit <= limit) 
                totalCnt += (curDigit * power(limit + 1, remLen - i - 1));
            else{
                totalCnt += power(limit + 1, remLen - i);
                return totalCnt;
            }
        }

        if(stoll(strSuffix) >= stoll(suffix))
            totalCnt++;

        return totalCnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
