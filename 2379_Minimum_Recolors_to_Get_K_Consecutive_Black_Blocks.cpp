class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i=0,j=0;
        int minOps = INT_MAX,countWhite=0;

        while(j < n){
            if(blocks[j] == 'W')
                countWhite++;

            
            if(j-i+1 == k){
                minOps = min(minOps,countWhite);
                if(blocks[i++] == 'W')
                    countWhite--;

            }
            j++;
        }
        return minOps;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
