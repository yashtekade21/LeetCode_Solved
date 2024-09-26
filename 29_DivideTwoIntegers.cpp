class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1)
            return 2147483647;

        return dividend/divisor;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
