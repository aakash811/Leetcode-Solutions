class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int left = 0, right = min(tasks.size(), workers.size());

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while(left < right) {
            int mid = (left + right + 1) / 2;
            int used = 0;
            multiset<int> free(workers.end() - mid, workers.end());

            bool flag = true;
            for(int i = mid - 1; i >= 0; --i) {
                auto it = prev(free.end());

                if(*it < tasks[i]) {
                    it = free.lower_bound(tasks[i] - strength);
                    if(it == free.end()) {
                        flag = false;
                        break;
                    }
                    ++used;
                    if(used > pills) {
                        flag = false;
                        break;
                    }
                }
                free.erase(it);
            }

            if(flag)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};