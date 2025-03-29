class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScore = findPrimeScores(nums);
        vector<int> nextConflict = findNextConflict(primeScore);
        vector<int> prevConflict = findPrevConflict(primeScore);
        vector<long long> subarrays = calcSubarrays(prevConflict, nextConflict);

        for(auto& ps:primeScore)
            cout<<ps<<" ";
        
        cout<<endl;

        for(auto& nc:nextConflict)
            cout<<nc<<" ";
        cout<<endl;

        for(auto&pc:prevConflict)
            cout<<pc<<" ";
        cout<<endl;

        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < nums.size(); i++)
            sortedNums.push_back({nums[i], i});

        sort(sortedNums.begin(), sortedNums.end(),greater<>());

        long long score = 1;
        int idx = 0;
        while (k > 0 && idx < sortedNums.size()) {
            auto& [num, i] = sortedNums[idx++];

            long long maxOp = min((long long)k, subarrays[i]);

            score = (score * binaryExpo(num, maxOp)) % MOD;

            k -= maxOp;
        }
        return score;
    }

private:
    vector<int> findPrimeScores(vector<int>& nums) {
        vector<int> primeScore(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            unordered_set<int> st;

            for (int j = 2; j * j <= num; j++) {
                while (num % j == 0) {
                    st.insert(j);
                    num /= j;
                }
            }
            if (num > 1) st.insert(num);
            primeScore[i] = st.size();
        }
        return primeScore;
    }

    vector<int> findNextConflict(vector<int>& primeScore) {
        vector<int> nextConflict(primeScore.size());
        stack<int> st;
        int n = primeScore.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScore[st.top()] <= primeScore[i]) {
                st.pop();
            }
            nextConflict[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextConflict;
    }

    vector<int> findPrevConflict(vector<int>& primeScore) {
        vector<int> prevConflict(primeScore.size());
        stack<int> st;
        int n = primeScore.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScore[st.top()] < primeScore[i]) {
                st.pop();
            }
            prevConflict[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevConflict;
    }

    vector<long long> calcSubarrays(vector<int>& prevConflict, vector<int>& nextConflict) {
        vector<long long> subarrays(prevConflict.size());
        for (int i = 0; i < prevConflict.size(); i++) {
            subarrays[i] = (long long)(nextConflict[i] - i) * (i - prevConflict[i]);
        }
        return subarrays;
    }

    long long binaryExpo(int num, int pow) {
        if (pow == 0) return 1;

        long long half = binaryExpo(num, pow / 2);
        long long ans = (half * half) % MOD;
        if (pow % 2) {
            ans = (ans * num) % MOD;
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
