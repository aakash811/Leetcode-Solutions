class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        unordered_map<int, int>ump;
        for(int i = 0; i < n; i++){
           ump[hand[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto it : ump){
            pq.push(it.first);
        }

        while(!pq.empty()){
            int first = pq.top();

            for(int i = 0; i < groupSize; i++){
                int curr = first + i;
                if(ump[curr] == 0){
                    return false;
                }
                ump[curr]--;
                if(ump[curr] == 0 && curr == pq.top()){
                    pq.pop();
                }
            }

            while(!pq.empty() && ump[pq.top()] == 0){
                pq.pop();
            }
        }
        return true;
    }
};