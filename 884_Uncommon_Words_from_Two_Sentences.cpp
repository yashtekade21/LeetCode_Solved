class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        vector<string> ans;

        istringstream iss1(s1);
        istringstream iss2(s2);
        string w1,w2;
        while(iss1>>w1){
            mp[w1]++;
        }
        while(iss2>>w2){
            mp[w2]++;
        }

        for(auto pair: mp)
            if(pair.second == 1)
                ans.emplace_back(pair.first);

        if(ans.empty()) return {};

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
