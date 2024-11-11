class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;

        for (auto n : nums) {
            int ub = n - prev;
            int largest_prev = 0;

            for (int i = ub - 1; i > 1; i--) {
                if (isprime(i)) {
                    largest_prev = i;
                    break;
                }
            }
            if (n - largest_prev <= prev)
                return false;

            prev = n - largest_prev;
        }
        return true;
    }

private:
    bool isprime(int N) {
        if ((!(N & 1) && N != 2))
            return false;
        for (int i = 3; i * i <= N; i += 2)
            if (!(N % i))
                return false;
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
