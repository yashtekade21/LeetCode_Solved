static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minLength(string s) {
        stack<char> stk;

        for(auto c:s){
            if(stk.empty())
                stk.push(c);
            else if(stk.top() == 'A' && c == 'B')
                stk.pop();
            else if(stk.top() == 'C' && c == 'D')
                stk.pop();
            else
                stk.push(c);
        }
        return stk.size();
    }
};
