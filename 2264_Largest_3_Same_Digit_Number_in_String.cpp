class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        priority_queue<int> pq;

        for (int i = 0; i < num.length() - 2; i++) {
           if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                int temp = stoi(num.substr(i,3));
                pq.push(temp);
           }
        }

        if(!pq.empty())
            ans = pq.top() == 0 ? "000" : to_string(pq.top());
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
