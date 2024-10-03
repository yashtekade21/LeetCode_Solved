class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;

        for(auto i:arr)
        {
            int rem = ((i%k)+k)%k;            
            freq[rem]++;
        }
        if(freq[0]%2 != 0)
            return false;

        for(int i=1;i<=k/2;i++)
        {
            if(freq[i]!=freq[k-i])
                return false;
        }
        return true;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
