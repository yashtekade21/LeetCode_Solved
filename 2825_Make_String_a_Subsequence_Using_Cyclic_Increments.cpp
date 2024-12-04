class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int s1 = str1.length(), s2 = str2.length();

        while (i < s1 && j < s2) {
            if ((str1[i] == str2[j]) || (cyclicID(str1[i]) == str2[j]))
                j++;

            i++;
        }

        return j == s2;
    }

private:
    char cyclicID(char ch) {
        if (ch == 'z')
            return 'a';
        return ch + 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
