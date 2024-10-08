class Solution {
public:
    int minSwaps(string s) {
        int openbracs = 0, closebracs = 0;

        for(auto c:s){
            if(c == '[')
                openbracs++;
            else if(openbracs>0 && c==']')
                openbracs--;
            else
                closebracs++;
        }
        return (closebracs+1)/2;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
