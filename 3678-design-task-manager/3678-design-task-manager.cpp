class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskMap;
    priority_queue<tuple<int, int, int>> pq;
    public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskMap[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {

        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop();

            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].first == userId && taskMap[taskId].second == priority) {
                rmv(taskId);
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