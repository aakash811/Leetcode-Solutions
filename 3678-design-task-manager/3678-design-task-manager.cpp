#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    priority_queue<pair<pair<int,int>, int>> pq; 
    unordered_map<int, pair<int,int>> mp;         

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            pq.push({{priority, taskId}, userId});
            mp[taskId] = {userId, priority};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({{priority, taskId}, userId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = mp[taskId];
        mp[taskId] = {userId, newPriority};
        pq.push({{newPriority, taskId}, userId}); 
    }
    
    void rmv(int taskId) {
        mp.erase(taskId); 
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [pri_task, userId] = pq.top();
            int priority = pri_task.first, taskId = pri_task.second;
            pq.pop();

            if (mp.find(taskId) != mp.end() && mp[taskId].second == priority) {
                mp.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};
