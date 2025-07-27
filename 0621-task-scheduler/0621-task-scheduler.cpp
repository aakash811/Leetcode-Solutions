class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        priority_queue<int>pq;

        unordered_map<char, int>ump;
        for(int i = 0; i < sz; i++){
            ump[tasks[i]]++;
        }

        for(auto it : ump){
            pq.push(it.second);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n + 1;
            
            for(int i = 0; i < cycle && !pq.empty(); i++){
                temp.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }

            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0){
                    pq.push(temp[i]);
                }
            }

            if(!pq.empty()){
                time += (cycle - temp.size());
            }
        }
        return time;
    }
};