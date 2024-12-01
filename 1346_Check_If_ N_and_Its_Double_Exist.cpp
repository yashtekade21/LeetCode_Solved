class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto i : arr)
            mp[i]++;

        for(auto i:arr){
            if(i != 0 && mp.find(2*i) != mp.end())
                return true;
            
            if(i==0 && mp[i] > 1)
                return true;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
