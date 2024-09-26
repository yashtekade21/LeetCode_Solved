class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        
        int count = 0;

        for(auto w1 : words1)
            mp1[w1]++;

        for(auto w2: words2)
            mp2[w2]++;

        unordered_map<string,int> ans;

        for(auto pair: mp1)
            if(pair.second == 1) 
                ans[pair.first]++;

        for(auto pair: mp2)
            if(pair.second == 1) 
                ans[pair.first]++;



        for(auto pair:ans)
            if(pair.second == 2) count++;

        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
