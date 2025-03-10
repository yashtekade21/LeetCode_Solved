class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        vector<int> consIdx(n);
        int curConsIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            consIdx[i] = curConsIdx;
            char ch = word[i];
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
                curConsIdx = i;
        }

        // for(auto& num:consIdx){
        //     cout<<num<<" ";
        // }
        unordered_map<char, int> vowelFreq;
        int consCnt = 0;
        int i = 0, j = 0;
        long long ans = 0;

        while (j < n) {
            char ch_j = word[j];
            if (ch_j == 'a' || ch_j == 'e' || ch_j == 'i' || ch_j == 'o' ||
                ch_j == 'u')
                vowelFreq[ch_j]++;
            else
                consCnt++;

            while (consCnt > k) {
                char ch_i = word[i];
                if (ch_i == 'a' || ch_i == 'e' || ch_i == 'i' || ch_i == 'o' ||
                    ch_i == 'u') {
                    vowelFreq[ch_i]--;
                    if (vowelFreq[ch_i] == 0)
                        vowelFreq.erase(ch_i);
                } else
                    consCnt--;

                i++;
            }

            while (consCnt == k && vowelFreq.size() == 5 && i < n) {
                int k = consIdx[j];
                ans += k - j;

                char ch_i = word[i];
                if (ch_i == 'a' || ch_i == 'e' || ch_i == 'i' || ch_i == 'o' ||
                    ch_i == 'u') {
                    vowelFreq[ch_i]--;
                    if (vowelFreq[ch_i] == 0)
                        vowelFreq.erase(ch_i);
                } else
                    consCnt--;

                i++;
            }
            j++;
        }
        // int ans = 0;
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
