class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n & 1;
        
        while(n != 0){
            n = n >> 1;
            int cur_bit = n & 1;
            if(cur_bit != bit)
                bit = cur_bit;
            else
                return false;    
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
