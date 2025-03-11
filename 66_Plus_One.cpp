class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.begin(),digits.end());

        int carry = 1;
        for(int i = ans.size()-1;i >= 0;i--){
            if(!carry)
                continue;
                
            if(ans[i] != 9){
                ans[i]++;
                carry = 0;
            }
            else
                ans[i] = 0;
        }

        if(carry == 1){
            ans.insert(ans.begin(),1);
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
