class Solution {
public:
    int maxDiff(int num) {
        string curNum = to_string(num);
        string maxNum = curNum, minNum = curNum;

        // maxNum
        char replaceMaxNum = '#';
        for (auto& ch : curNum) {
            if (ch != '9') {
                replaceMaxNum = ch;
                break;
            }
        }

        if (replaceMaxNum != '#')
            replace(maxNum.begin(), maxNum.end(), replaceMaxNum, '9');

        // minNum
        for (int i = 0; i < minNum.length(); i++) {
            char ch = curNum[i];

            if (i == 0 && ch != '1') {
                replace(minNum.begin(), minNum.end(), ch, '1');
                break;
            } else if (ch != '0' && ch != minNum[0]) {
                replace(minNum.begin(), minNum.end(), ch, '0');
                break;
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
