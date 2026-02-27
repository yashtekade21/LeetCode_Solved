class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int initialZeros = 0;
        for (char& ch : s) {
            if (ch == '0')
                initialZeros++;
        }

        if (initialZeros == 0)
            return 0;

        vector<int> operations(n + 1, -1);
        set<int> evenSet, oddSet;

        for (int count = 0; count <= n; count++) {
            if (count % 2 == 0)
                evenSet.insert(count);
            else
                oddSet.insert(count);
        }

        queue<int> q;
        q.push(initialZeros);
        operations[initialZeros] = 0;

        if (initialZeros % 2 == 0)
            evenSet.erase(initialZeros);
        else
            oddSet.erase(initialZeros);

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);

            set<int>& currSet = (min_new_z % 2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while (it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if (newZ == 0)
                        return operations[newZ];

                    q.push(newZ);
                }

                it = currSet.erase(it);
            }
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
