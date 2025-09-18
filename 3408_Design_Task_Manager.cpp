class TaskManager {
public:
    priority_queue<pair<int, int>> pq; // priority, taskid
    unordered_map<int, pair<int, int>>
        taskUserPriorityMp; // taskid -> userid, priority

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId,taskId,priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskUserPriorityMp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        int userId = taskUserPriorityMp[taskId].first;

        taskUserPriorityMp[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        int userId = taskUserPriorityMp[taskId].first;
        taskUserPriorityMp[taskId] = {userId, -1};
    }

    int execTop() {
        while (!pq.empty()) {
            int priority = pq.top().first;
            int taskId = pq.top().second;
            int userId = taskUserPriorityMp[taskId].first;
            int newPriority = taskUserPriorityMp[taskId].second;

            if (priority != newPriority || newPriority == -1)
                pq.pop();
            else{
                taskUserPriorityMp[taskId] = {userId,-1};
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
