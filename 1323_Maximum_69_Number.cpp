class Solution {
public:
    int maximum69Number(int num) {
        string temp = to_string(num);

        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '6') {
                temp[i] = '9';
                break;
            }
        }

        return stoi(temp);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
