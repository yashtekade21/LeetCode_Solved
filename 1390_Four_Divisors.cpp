class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        unordered_map<int, int> mp;
        for (auto& num : nums)
            mp[num]++;

        for (auto [num, freq] : mp) {
            vector<int> divisors = getDivisors(num);
            if (divisors.size() == 4) {
                long long sum =
                    accumulate(divisors.begin(), divisors.end(), 0LL);

                ans += (long long)sum * freq;
            }
        }
        return ans;
    }

private:
    vector<int> getDivisors(int num) {
        vector<int> divs;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                divs.emplace_back(i);
                if (i != num / i)
                    divs.emplace_back(num / i);
            }
        }
        return divs;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
