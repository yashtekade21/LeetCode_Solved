static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        string wd = "";
        vector<string> sent1words, sent2words;

        while (ss1 >> wd)
            sent1words.emplace_back(wd);

        ss1.str("");
        ss1.clear();

        while (ss2 >> wd)
            sent2words.emplace_back(wd);

        ss2.str("");
        ss2.clear();

        int s1size = sent1words.size();
        int s2size = sent2words.size();
        if (s1size > s2size) {
            swap(sent1words, sent2words);
            swap(s1size, s2size);
        }

        int start = 0, s1end = s1size - 1, s2end = s2size - 1;

        while (start < s1size && sent1words[start] == sent2words[start])
            start++;

        while (s1end >= 0 && sent1words[s1end] == sent2words[s2end]) {
            s1end--;
            s2end--;
        }
        if(s1end < start)
            return true;
    
        return false;
    }
};
