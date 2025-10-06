//Greedy & Union Find
class UnionFind { 
public:   
    short root[2500], rank[2500];
    UnionFind(int n) {
        memset(rank, 1, sizeof(short)*n);
        iota(root, root+n, 0);
    }

    int Find(int x) {
        return (x == root[x])?x:root[x]=Find(root[x]);
    }

    void Union(int x, int y) {
        x= Find(x), y= Find(y);
        if (x == y)  return;
        if (rank[x] > rank[y]) swap(x, y);   
        root[x] = y;
        if (rank[x]==rank[y]) rank[y]++;
    }
};
class Solution {
public:
    using int2=pair<int, int>;
    using int3=pair<int, int2>; // (wt, v, w)
    int n;
    int to1D(int i, int j){
        return i*n+j;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;// edge case

        //Build bucket
        vector<int2> bucket[2501];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (i<n-1){
                    int wt=max(grid[i][j], grid[i+1][j]);
                    bucket[wt].emplace_back(to1D(i, j), to1D(i+1, j));
                }
                if (j<n-1){
                    int wt=max(grid[i][j], grid[i][j+1]);
                    bucket[wt].emplace_back(to1D(i, j), to1D(i, j+1));
                }
            }
        }
        const int V=n*n;
        UnionFind uf(V);
        for (int wt=0; wt<=V; wt++){
            for (auto& [v, w] : bucket[wt])
                uf.Union(v, w);
            if (uf.Find(0)==uf.Find(V-1))
                return wt;
        }
        return 0;
    }
};