class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        string ans;

        int carry = 0, sum = 0;

        while (n - 1 >= 0 || m - 1 >= 0) {
            sum = carry;

            if (n - 1 >= 0) {
                sum += (a[n - 1] - '0');
                n--;
            }

            if (m - 1 >= 0) {
                sum += (b[m - 1] - '0');
                m--;
            }

            ans.push_back((sum % 2 == 0) ? '0' : '1');
            carry = sum / 2;
        }

        if (carry)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
