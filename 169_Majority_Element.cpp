#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el,cnt = 0;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt = 1;
            } else if (nums[i] == el)
                cnt++;
            else
                cnt--;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el)
                ans++;
        }

        if (ans > (n / 2))
            return el;

        return -1;
    }
};
