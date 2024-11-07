class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int comb = 0;

        for(int i=0;i<25;i++){
            int setbit = 0;
            for(auto x:candidates)
                if((x>>i) & 1)
                    setbit++;
            comb = max(comb,setbit);
        }
        return comb;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
