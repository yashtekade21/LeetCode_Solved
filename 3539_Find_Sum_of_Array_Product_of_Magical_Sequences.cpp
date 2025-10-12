class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    int n;
    map<tuple<ll, int , int, int>, ll> dp;
    vector<ll> fact;
    vector<ll> invFact;

    int magicalSum(int m, int k, vector<int>& nums) {
        n = nums.size();

        fact.assign(m+1, 1);
        invFact.assign(m+1, 1);

        for(int i = 2; i <= m; i++) 
            fact[i] = (fact[i-1] * i) % MOD;
        
        for(int i = 0; i <= m; i++) 
            invFact[i] = power(fact[i], MOD-2);
        
        return (int)(solve(0,nums, m, k, 0) % MOD);
    }

private:
    ll solve(ll sum, vector<int>& nums, int m, int k,int idx) {
        auto key = make_tuple(sum,m,k,idx);

        if(dp.count(key))
            return dp[key];

        if(m == 0 && __builtin_popcount(sum) == k) 
            return 1;
        

        if(m == 0 || idx >= n) 
            return 0;
        
        ll totalSum = 0;

        totalSum = (totalSum + solve((sum >> 1),nums, m, k - (sum & 1), idx+1)) % MOD;

        for(int freq = 1; freq <= m; freq++) {
            ll newSum = sum + freq;

            ll mul = solve((newSum >> 1),nums, m - freq, k - (newSum & 1), idx+1);

            mul = (power(nums[idx], freq) % MOD * mul % MOD) % MOD;

            mul = (mul * nCr(m, freq)) % MOD;

            totalSum = (totalSum + mul) % MOD;
        }

        return dp[key] = totalSum;
    }

    ll power(ll base,ll exp){
        if(exp == 0)
            return 1;
        
        ll half = power(base,exp/2);
        ll ans = (half * half) % MOD;

        if(exp % 2 == 1)
            return (ans * base) % MOD;
        return ans % MOD;
    }

    ll nCr(int n, int r) {
        return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
