class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> s;
        vector<int> ans(prices.begin(),prices.end());
        for(int i=0;i<n;i++){
            while(!s.empty() && prices[i] <= prices[s.top()]){
                ans[s.top()] -= prices[i];
                s.pop(); 
            }
            s.push(i);
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
