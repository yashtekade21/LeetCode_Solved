class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
    
        vector<string> parent;
        parent.emplace_back(folder[0]);
        string last_stack = folder[0];

        for(int i=1;i<folder.size();i++){
            string s = folder[i];
            if(s.find(last_stack+'/') != 0){
                parent.emplace_back(s);
                last_stack = s;
            }
        }
        return parent;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
