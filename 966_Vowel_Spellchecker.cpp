class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, string> caseMp, vowMp;

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        st.clear();
        caseMp.clear();
        vowMp.clear();

        for (auto& word : wordlist) {
            st.insert(word);

            string lowerCase = toLower(word);
            if (caseMp.find(lowerCase) == caseMp.end()) {
                caseMp[lowerCase] = word;
            }

            string maskedStr = maskVowels(lowerCase);
            if (vowMp.find(maskedStr) == vowMp.end()) {
                vowMp[maskedStr] = word;
            }
        }

        vector<string> ans;

        for (auto& query : queries) {
            ans.push_back(checkMatch(query));
        }
        return ans;
    }

private:
    string toLower(string& s) {
        string lowerCase = s;
        for (auto& ch : lowerCase)
            ch = tolower(ch);
        return lowerCase;
    }

    string maskVowels(string& s) {
        string maskedStr = s;
        for (char& ch : maskedStr) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ch = '*';
        }
        return maskedStr;
    }

    string checkMatch(string& query) {
        if (st.find(query) != st.end())
            return query;

        string lowerCase = toLower(query);
        if (caseMp.find(lowerCase) != caseMp.end())
            return caseMp[lowerCase];

        string maskedStr = maskVowels(lowerCase);
        if (vowMp.find(maskedStr) != vowMp.end())
            return vowMp[maskedStr];

        return "";
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
