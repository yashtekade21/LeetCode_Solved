class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cntEven = 0, cntOdd = 0;

        for (auto& num : nums) {
            if (num % 2 == 0)
                cntEven++;
            else
                cntOdd++;
        }

        int parity = nums[0] % 2;
        int alternateParityLen = 1;

        for (int i = 1; i < n; i++) {
            int curParity = nums[i] % 2;
            if (curParity != parity) {
                alternateParityLen++;
                parity = curParity;
            }
        }

        return max(cntEven, max(cntOdd, alternateParityLen));
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
