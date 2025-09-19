class Spreadsheet {
public:
    unordered_map<string, int>ump;
    int solve(string op){
        if(isdigit(op[0])){
            return stoi(op);
        }

        return ump.count(op) ? ump[op] : 0;
    }

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        ump[cell] = value;
    }
    
    void resetCell(string cell) {
        ump.erase(cell);
    }
    
    int getValue(string formula) {
        if(formula[0] == '='){
            formula = formula.substr(1);
            int plus = formula.find('+');
            string lo = formula.substr(0, plus);
            string hi = formula.substr(plus + 1);

            return solve(lo) + solve(hi);
        }
        return stoi(formula);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */