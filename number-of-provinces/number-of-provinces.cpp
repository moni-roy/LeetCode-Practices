class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int total;
public:
    UnionFind(int n): parent(n), rank(n, 0), total(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        total--;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size() {
        return total;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return usingUnionFind(isConnected);
    }
private:
    int usingUnionFind(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.size();
    }
    int usingDFS(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vs(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vs[i] == 0) {
                dfs(i, vs, isConnected);
                ans ++;
            }
        }
        return ans;
    }
    void dfs(int p, vector<int> &vs, vector<vector<int>>& is) {
        if(vs[p]) return;
        vs[p] = 1;
        for(int i = 0; i < is.size(); i++) {
            if(!vs[i] && i!=p && is[p][i]) dfs(i, vs, is);
        }
    }
};