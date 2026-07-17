class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));
        vector<int> ans;

        vector<int> freq(maxVal + 1, 0);
        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    freq[j]++;
                    if (num / j != j) {
                        freq[num / j]++;
                    }
                }
            }
        }

        vector<long long> gcdPairs(maxVal + 1, 0);
        for (int k = maxVal; k >= 1; k--) {
            long long cnt = freq[k];

            gcdPairs[k] = cnt * (cnt - 1) / 2;

            for (int m = 2 * k; m <= maxVal; m += k)
                gcdPairs[k] -= gcdPairs[m];
        }

        vector<long long> prefixCntGcd(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++)
            prefixCntGcd[g] = prefixCntGcd[g - 1] + gcdPairs[g];

        for (long long idx : queries) {
            int l = 1;
            int r = maxVal;
            int temp = 1;
            while (l <= r) {
                int m = l + (r - l) / 2;

                if (prefixCntGcd[m] > idx) {
                    temp = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
