#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;

        for (char c : s) {
            freq[c]++;
        }

        for (auto &[ch, count] : freq) {
            pq.push({count, ch});
        }

        string ans;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            ans.append(count, ch);
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
