class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        if(n == 0 || m == 0){
            return 0;
        }

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int cnt = 0;
        int idx = m - 1;
        for(int i = n - 1; i >= 0 && idx >= 0; i--){
            if(players[i] <= trainers[idx]){
                cnt++;
                idx--;
            }
        }
        return cnt;
    }
};