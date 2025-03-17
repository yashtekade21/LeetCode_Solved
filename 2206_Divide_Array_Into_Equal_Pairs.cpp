class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> freq;
        int posPairs = 0;

        for(auto& num:nums){
            freq[num]++;

            if(freq[num] % 2 == 0)
                posPairs++;
        }

        return posPairs >= n/2;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
