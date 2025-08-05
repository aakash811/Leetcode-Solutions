class FreqStack {
public:
    unordered_map<int, int>ump;
    unordered_map<int, stack<int>>mp;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++ump[val]);
        mp[ump[val]].push(val);
    }
    
    int pop() {
        int val = mp[maxFreq].top();
        mp[maxFreq].pop();
        if(mp[maxFreq].empty()){
            maxFreq--;
        }
        ump[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */