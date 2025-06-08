class Solution {
public:
    void dfs(int num, int n, vector<int>& res){
        if(num > n){
            return;
        }
        res.push_back(num);
        for(int i = 0; i < 10; i++){
            int x = num * 10 + i;
            if(x > n){
                return;
            }
            dfs(x, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i = 1; i < 10; i++){
            dfs(i, n, res);
        }   
        return res;
    }
};