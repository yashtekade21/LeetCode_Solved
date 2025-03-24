class Solution {
public:
    string reverseVowels(string s) {
        string ans = s;
        int n = s.length();

        int i = 0, j = n - 1;
        string vowels = "aeiouAEIOU";

        while (i < j) {
            if (vowels.find(ans[i]) == string::npos){
                i++;
            }
            if(vowels.find(ans[j]) == string::npos){
                j--;
            }

            if(vowels.find(ans[j]) != string::npos && vowels.find(ans[i]) != string::npos){
                swap(ans[i],ans[j]);
                i++;
                j--;
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
