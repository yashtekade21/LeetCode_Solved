class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j] <= prices[i] && j > i){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
