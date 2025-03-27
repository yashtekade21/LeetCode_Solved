class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n = candies.size();

        int maxEl = INT_MIN;

        for(int& candy:candies){
            maxEl = max(maxEl,candy);
        }

        // cout<<maxEl<<endl;
        for(int& candy:candies){
            if(candy + extraCandies >= maxEl){
                ans.emplace_back(true);
            }
            else{
                ans.emplace_back(false);
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
