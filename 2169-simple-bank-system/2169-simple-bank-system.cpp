class Bank {
public:
    vector<long long>vec;
    Bank(vector<long long>& balance) {
        for(int i = 0; i < balance.size(); i++){
            vec.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        int n = vec.size();
        if(account1 <= n && account2 <= n){
            if(vec[account1 - 1] >= money){
                vec[account1 - 1] -= money;
                vec[account2 - 1] += money;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        int n = vec.size();
        if(account - 1 <= n){
            vec[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        int n = vec.size();
        if(account - 1 <= n && vec[account - 1] >= money){
            vec[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */