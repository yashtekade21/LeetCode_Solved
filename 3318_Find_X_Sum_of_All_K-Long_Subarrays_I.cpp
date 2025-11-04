class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;
        vector<int> ans;

        int i = 0, j = 0;
        while (j < n) {
            mp[nums[j]]++;
            if (j - i + 1 == k) {
                ans.push_back(solve(mp, x));

                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }

private:
    int solve(unordered_map<int, int>& mp, int x) {
        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& it : mp) {
            pq.push({it.second, it.first});

            if (pq.size() > x)
                pq.pop();
        }

        int sum = 0;
        while (!pq.empty()) {
            int freq = pq.top().second;
            int num = pq.top().first;
            pq.pop();

            sum += (freq * num);
        }
        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
