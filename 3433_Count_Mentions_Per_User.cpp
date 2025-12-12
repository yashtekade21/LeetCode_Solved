class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        auto customSort = [](auto& vec1, auto& vec2) {
            int timeStamp1 = stoi(vec1[1]), timeStamp2 = stoi(vec2[1]);
            if (timeStamp1 == timeStamp2)
                return vec1[0][0] > vec2[0][0];

            return timeStamp1 < timeStamp2;
        };
        sort(events.begin(), events.end(), customSort);
        vector<int> offlineStatus(numberOfUsers), ans(numberOfUsers);

        for (auto& event : events) {
            string message = event[0];
            int timeStamp = stoi(event[1]);

            if (message == "OFFLINE") {
                int userId = stoi(event[2]);
                offlineStatus[userId] = timeStamp;
            } else {
                vector<string> ids;
                stringstream ss(event[2]);
                string token;
                while (ss >> token)
                    ids.push_back(token);

                for (auto& id : ids) {
                    if (id == "HERE") {
                        for (int user = 0; user < numberOfUsers; user++) {
                            if (offlineStatus[user] == 0 ||
                                offlineStatus[user] + 60 <= timeStamp)
                                ans[user]++;
                        }
                    } else if (id == "ALL") {
                        for (int user = 0; user < numberOfUsers; user++)
                            ans[user]++;

                    } else {
                        int user = stoi(id.substr(2));
                        ans[user]++;
                    }
                }
            }
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
