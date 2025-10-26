class Bank {
public:
    int n;
    unordered_map<int, long long> mp;
    Bank(vector<long long>& balance) {
        n = balance.size();

        for (int i = 0; i < n; i++)
            mp[i + 1] = balance[i];
    }

    bool transfer(int acc1, int acc2, long long money) {
        if (acc1 > n || acc2 > n || (mp[acc1] < money))
            return false;

        mp[acc1] -= money;
        mp[acc2] += money;
        return true;
    }

    bool deposit(int acc, long long money) {
        if (acc > n)
            return false;

        mp[acc] += money;
        return true;
    }

    bool withdraw(int acc, long long money) {
        if (acc > n || mp[acc] < money)
            return false;

        mp[acc] -= money;
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
