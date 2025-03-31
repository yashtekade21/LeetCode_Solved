class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(auto& num:arr)
            mp[num]++;

        priority_queue<int> pq;

        for(auto& [num,freq]:mp){
            pq.push(freq);
        }

        int curFreq = pq.top();
        pq.pop();

        while(!pq.empty()){
            if(pq.top() == curFreq){
                return false;
            }
            curFreq = pq.top();
            pq.pop();
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
