class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int size = s.length();
        if (size == 1 || size == 0)
            return num;

        vector<int> rightMax(size, 0);

        int maxPos = size - 1;
        rightMax[size - 1] = maxPos;

        for (int i = size - 2; i >= 0; i--) {
            if (s[i] > s[rightMax[i + 1]])
                maxPos = i;
            rightMax[i] = maxPos;
        }

        for (int i = 0; i < size; i++) {
            if (s[i] != s[rightMax[i]]) {
                swap(s[i], s[rightMax[i]]);
                return stoi(s);
            }
        }
        return num;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
