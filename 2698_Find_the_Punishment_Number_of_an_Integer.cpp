class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int num = 1; num <= n; num++) {
            int sq = num * num;

            if (check_punish_num(sq, num, 0))
                ans += sq;
        }
        return ans;
    }
private:
    bool check_punish_num(int sq,int n, int cur_sum){
        if(sq == 0)
            return cur_sum == n;

        if(cur_sum > n)
            return false;

        return check_punish_num(sq/10,n,cur_sum + sq%10) || 
                check_punish_num(sq/100,n,cur_sum+ sq%100) || 
                check_punish_num(sq/1000,n,cur_sum + sq%1000) ||
                check_punish_num(sq/10000,n,cur_sum + sq%10000);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
