class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int s1 = str1.length(), s2 = str2.length();

        if (str1 + str2 != str2 + str1)
            return ans;

        ans = str1.substr(0, gcd(s1, s2));
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
