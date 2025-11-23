class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = accumulate(nums.begin(), nums.end(), 0);

        int rem = ans % 3;

        vector<int> r1, r2;

        for (int num : nums) {
            if (num % 3 == 1)
                r1.push_back(num);
            else if (num % 3 == 2)
                r2.push_back(num);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if (rem == 1) {
            int op1 = r1.size() >= 1 ? ans - r1[0] : INT_MIN;
            int op2 = r2.size() >= 2 ? ans - (r2[0] + r2[1]) : INT_MIN;
            return max(op1, op2);
        }

        if (rem == 2) {
            int op1 = r2.size() >= 1 ? ans - r2[0] : INT_MIN;
            int op2 = r1.size() >= 2 ? ans - (r1[0] + r1[1]) : INT_MIN;
            return max(op1, op2);
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
