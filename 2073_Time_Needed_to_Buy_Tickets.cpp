class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while (tickets[k] >= 0) {
            if (tickets[k] == 0)
                return time;

            for (int j = 0; j < tickets.size(); j++) {
                if (tickets[j] == 0)
                    continue;
                else {
                    tickets[j]--;
                    time++;
                    if (tickets[k] == 0)
                    return time;

                }
            }
        }
        return time;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
