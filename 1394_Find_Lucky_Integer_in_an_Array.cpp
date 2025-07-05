class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            freq[num]++;
        }

        for (int num = 500; num > 0; num--) {
            if (freq[num] == num) {
                ans = num;
                break;
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
