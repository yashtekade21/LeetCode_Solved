class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        unordered_map<char,int> mp;

        for(int i=0;i<allowed.length();i++)
        {
            mp[allowed[i]]++;
        }
        int j=0;
        for(int i=0;i<words.size();i++)
        {
            for(j=0;j<words[i].length();j++)
            {
                if(mp[words[i][j]] != 1)
                    break;
                
            }
            if(j==words[i].length())
                count++;
        }
        return count;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
