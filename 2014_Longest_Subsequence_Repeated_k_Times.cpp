class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        int n = s.length();
        vector<int> mp(26, 0);
        for (auto& ch : s)
            mp[ch - 'a']++;

        vector<bool> isUsableinSubseq(26, false);
        vector<int> atMostUsable(26, 0);
        for (int i = 0; i < 26; i++) {
            if (mp[i] >= k) {
                isUsableinSubseq[i] = true;
                atMostUsable[i] = mp[i] / k;
            }
        }

        int maxLenofSubseq = n / k;

        string curSubseq = "";
        solve(s, curSubseq, isUsableinSubseq, atMostUsable, k, maxLenofSubseq,
              ans);

        return ans;
    }

private:
    bool isSubsequence(string s, string sub, int k) {
        int i = 0, j = 0;
        int n = s.length(), m = sub.length();

        while (i < n && j < m * k) {
            if (s[i] == sub[j % m])
                j++;
            i++;

            if (j == m * k)
                return true;
        }
        return false;
    }

    void solve(string& s, string& curSubseq, vector<bool>& isUsableinSubseq,
               vector<int>& atMostUsable, int k, int maxLenofSubseq,
               string& ans) {
        if (curSubseq.length() > maxLenofSubseq)
            return;

        if ((curSubseq.length() > ans.length() ||
             (curSubseq.length() == ans.length() && curSubseq > ans)) &&
            isSubsequence(s, curSubseq, k)) {
            ans = curSubseq;
        }

        for (int i = 0; i < 26; i++) {
            if (isUsableinSubseq[i] && atMostUsable[i] > 0) {

                // add char to curSubseq
                char ch = i + 'a';
                curSubseq += ch;
                atMostUsable[i]--;

                // check if we can add more
                solve(s, curSubseq, isUsableinSubseq, atMostUsable, k,
                      maxLenofSubseq, ans);

                // remove already added to try combinations
                curSubseq.pop_back();
                atMostUsable[i]++;
            }
        }
        return;
    }
};
