class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int, int>ump;
        priority_queue<int, vector<int>, greater<int>>pq;

        if(n % groupSize != 0){
            return false;
        }

        for(int i = 0; i < n; i++){
            ump[hand[i]]++;
        }
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
                
                if(ump[curr] == 0 && pq.top() == curr){
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