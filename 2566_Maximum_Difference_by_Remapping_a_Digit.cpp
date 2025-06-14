class Solution {
public:
    int minMaxDifference(int num) {
        string numString = to_string(num);
        string minNum = numString;
        string maxNum = numString;

        char remapNumMax = '#';
        char remapNumMin = '#';

        for (auto& num : maxNum) {
            if (num != '9') {
                remapNumMax = num;
                break;
            }
        }
        for (auto& num : minNum) {
            if (num != '0') {
                remapNumMin = num;
                break;
            }
        }

        for (auto& num : maxNum)
            num = (num == remapNumMax) ? '9' : num;

        for (auto& num : minNum)
            num = (num == remapNumMin) ? '0' : num;

        return stoi(maxNum) - stoi(minNum);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
