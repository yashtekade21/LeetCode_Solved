class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        for (auto& curFolder : folder)
            st.insert(curFolder);

        vector<string> ans;
        for (auto& curFolder : folder) {
            bool isSubFolder = false;
            string tempFolder = curFolder;
            while (!curFolder.empty()) {
                auto posLast = curFolder.find_last_of('/');
                curFolder = curFolder.substr(0, posLast);

                if (st.find(curFolder) != st.end()) {
                    isSubFolder = true;
                    break;
                }
            }

            if (!isSubFolder)
                ans.push_back(tempFolder);
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
