class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> indegree,outdegree;
        vector<int> path;
        vector<vector<int>> ans;
        stack<int> s;

        for(auto e:pairs){
            mp[e[0]].emplace_back(e[1]);
            outdegree[e[0]]++;
            indegree[e[1]]++;
        }

        int start_node = pairs[0][0];
        for(auto it:mp){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                start_node = node;
                break;
            }
        }

        s.push(start_node);
        while(!s.empty()){
            int cur = s.top();

            if(!mp[cur].empty()){
                int adj = mp[cur].back();
                mp[cur].pop_back();
                s.push(adj);
            }
            else{
                path.emplace_back(cur);
                s.pop();
            }
        }
        reverse(path.begin(),path.end());
        
        for(int i=0;i<path.size()-1;i++)
            ans.emplace_back(vector<int>{path[i],path[i+1]});
        
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
