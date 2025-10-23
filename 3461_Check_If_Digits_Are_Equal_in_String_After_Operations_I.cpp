class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = s;

        while (temp.size() != 2) {
            string newStr = "";
            for (int i = 0; i < temp.size() - 1; i++)
                newStr += (temp[i] + temp[i + 1]) % 10;

            temp = newStr;
        }

        return temp[0] == temp[1];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
