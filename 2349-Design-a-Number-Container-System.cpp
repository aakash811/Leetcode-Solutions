class NumberContainers {
public:
    unordered_map<int,int>ump;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>pq;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(ump.count(index) && ump[index] == number)
       return;
       ump[index] = number;
       pq[number].push(index); 
    }
    
    int find(int number) {
        if(!pq.count(number))
        {
            return -1;
        }
        auto &it = pq[number];
        while(!it.empty() && ump[it.top()] != number)
        {
            it.pop();
        }
        return it.empty() ? -1 : it.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */