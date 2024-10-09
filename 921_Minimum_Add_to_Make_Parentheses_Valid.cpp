static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;

        for(auto c:s){
            if(c=='(')
                open++;
            else if(open > 0 && c==')')
                open--;
            else
                close++;
        }
        return open+close;
    }
};
