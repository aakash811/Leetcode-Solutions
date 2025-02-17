class Solution {
public:
    int backtrack(string& tiles, vector<bool>& vis){
        int count = 0;
        for(int i = 0; i < tiles.size(); i++)
        {
            if(vis[i] || (i > 0 && tiles[i] == tiles[i - 1] && !vis[i - 1]))
            {
                continue;
            }
            vis[i] = true;
            count += 1 + backtrack(tiles, vis);
            vis[i] = false;
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> vis(tiles.size(), false);
        return backtrack(tiles, vis);
    }
};