class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int unlocked = complexity[0];
        int minEl = *min_element(complexity.begin() + 1, complexity.end());

        if (minEl <= unlocked)
            return 0;

        return fact(n - 1) % MOD;
    }

private:
    int fact(int n) {
        if (n <= 1)
            return 1;
        return (long long)n * fact(n - 1) % MOD;
    }
};
