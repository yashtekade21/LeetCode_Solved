class Solution {
public:
    long long ans = 0;
    long long kMirror(int k, int n) {
        int len = 1;

        while (n > 0) {
            generatePalindrome(len, k, n);
            len++;
        }
        
        return ans;
    }

private:
    void generatePalindrome(int& len, int& k, int& n) {
        int halfLen = (len + 1) / 2;

        long long minNum = power(10, halfLen - 1);
        long long maxNum = power(10, halfLen) - 1;

        for (int num = minNum; num <= maxNum; num++) {
            string firstHalf = to_string(num);
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());

            string palStr = "";

            if (len % 2 == 0) // even palindrome number
                palStr = firstHalf + secondHalf;
            else // odd palindrome number
                palStr = firstHalf + secondHalf.substr(1);

            long long palNum = stoll(palStr);
            string kBaseNum = BasekNum(palNum, k);

            if (isPalindrome(kBaseNum)) {
                ans += palNum;
                n--;
                if (n == 0)
                    break;
            }
        }
    }

    bool isPalindrome(string n) {
        return equal(n.begin(), n.end(), n.rbegin());
    }

    string BasekNum(long long n, int base) {
        if (n == 0)
            return "0";

        string kBaseNum = "";
        while (n) {
            kBaseNum += to_string(n % base);
            n /= base;
        }

        return kBaseNum;
    }

    long long power(long long base, int exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long result = half * half;
        if (exp % 2 == 1)
            return result * base;

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
