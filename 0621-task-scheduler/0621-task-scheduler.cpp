class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>mpp(26, 0);

        for(auto it : tasks){
            mpp[it - 'A']++;
        }

        for(auto it : mpp){
            if(it){
                pq.push(it);
            }
        }
        int time = 0;
        while(!pq.empty()){
            int cycle = n + 1;
            vector<int>rem;
            
            while(!pq.empty() && cycle){
                int freq = pq.top();
                pq.pop();
                if(freq > 1){
                    rem.push_back(freq - 1);
                }
                time++;
                cycle--;
            }

            for(auto it : rem){
                pq.push(it);
            }

            if(pq.empty()){
                break;
            }
            time += cycle;
        }
        return time;
    }
};