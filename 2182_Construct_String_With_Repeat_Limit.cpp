class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        vector<int> freq(26, 0);
        priority_queue<char> pq;
        for (auto c : s)
            freq[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freq[i])
                pq.push('a' + i);
        }
        string ans = "";
        while (!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int cnt = min(freq[ch - 'a'], rl);

            ans.append(cnt, ch);
            freq[ch - 'a'] -= cnt;

            if (freq[ch - 'a'] && !pq.empty()) {
                int nxtch = pq.top();
                pq.pop();

                ans += nxtch;
                freq[nxtch - 'a']--;

                if (freq[nxtch - 'a'])
                    pq.push(nxtch);

                pq.push(ch);
            }
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
