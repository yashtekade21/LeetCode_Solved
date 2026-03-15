class Fancy {
public:
    long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long add, mul;
    Fancy() {
        add = 0;
        mul = 1;
    }

    void append(int val) {
        long long newNum =
            ((val - add) % MOD + MOD) * power(mul, MOD - 2) % MOD;
        seq.emplace_back(newNum);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;

        return (seq[idx] * mul + add) % MOD;
    }

private:
    long long power(int base, int exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long ans = (half * half) % MOD;

        if (exp % 2 != 0)
            ans = (ans * base) % MOD;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
