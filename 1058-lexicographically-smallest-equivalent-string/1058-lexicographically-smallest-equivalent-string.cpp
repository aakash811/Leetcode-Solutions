class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent[i]);
    }

    void unite(int i, int j) {
        int irep = find(i);
        int jrep = find(j);
        if (irep == jrep)
        {
            return;
        }

        if (irep < jrep)
        {
            parent[jrep] = irep;
        }
        else
        {
            parent[irep] = jrep;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        UnionFind uf(26);
        
        for(int i = 0; i < n; i++){
            char u = s1[i];
            char v = s2[i];
            uf.unite(u - 'a', v - 'a');
        }

        string res = "";
        for (char ch : baseStr) 
        {
            res += (char)(uf.find(ch - 'a') + 'a');
        }

        return res;
    }
};