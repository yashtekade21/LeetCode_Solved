class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int maxi = nums[0], lastmax = INT_MIN, bits = setbits(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            bool bitchanged = false;
            if (bits != setbits(nums[i])) {
                bitchanged = true;
                lastmax = maxi;
            }

            if (nums[i] > maxi) {
                maxi = nums[i];
                bits = setbits(maxi);
            }

            if (nums[i] < lastmax)
                return false;
        }
        return true;
    }

private:
    int setbits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
