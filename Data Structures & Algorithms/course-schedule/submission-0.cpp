class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0); // 0 = unvisited, 1 = visiting, 2 = done

        for (auto &p : pre) {
            adj[p[1]].push_back(p[0]); // course p[1] → prerequisite for p[0]
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0 && !dfs(i, adj, vis)) {
                return false; // cycle found
            }
        }
        return true;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node] == 1) return false; // cycle (back edge)
        if (vis[node] == 2) return true;  // already processed safely

        vis[node] = 1; // mark as visiting
        for (auto nei : adj[node]) {
            if (!dfs(nei, adj, vis)) return false;
        }
        vis[node] = 2; // mark as done
        return true;
    }
};
