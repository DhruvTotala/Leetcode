class TaskManager {
    struct Task {
        int taskId;
        int priority;
        bool operator<(const Task &other) const {
            if (priority != other.priority)
                return priority > other.priority; // higher first
            return taskId > other.taskId;        // larger id first
        }
    };

    map<Task, int> taskQueue;
    unordered_map<int, int> taskPriorityMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskQueue[{taskId, priority}] = userId;
            taskPriorityMap[taskId] = priority;
        }
    }

    void add(int userId, int taskId, int priority) {
        taskQueue[{taskId, priority}] = userId;
        taskPriorityMap[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int oldPriority = taskPriorityMap[taskId];
        int userId = taskQueue[{taskId, oldPriority}];
        taskQueue.erase({taskId, oldPriority});
        taskQueue[{taskId, newPriority}] = userId;
        taskPriorityMap[taskId] = newPriority;
    }

    void rmv(int taskId) {
        if (!taskPriorityMap.count(taskId)) return;
        int priority = taskPriorityMap[taskId];
        taskQueue.erase({taskId, priority});
        taskPriorityMap.erase(taskId);
    }

    int execTop() {
        if (taskQueue.empty()) return -1;
        auto it = taskQueue.begin();
        int userId = it->second;
        taskPriorityMap.erase(it->first.taskId);
        taskQueue.erase(it);
        return userId;
    }
};