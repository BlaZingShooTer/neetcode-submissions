class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // minHeap = {currentTime, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<>
        > minHeap;

        // dist[r][c] = minimum maximum elevation
        // required to reach (r, c)
        vector<vector<int>> dist(
            n,
            vector<int>(m, INT_MAX)
        );

        // This will store the path for every cell
        vector<vector<vector<int>>> path(
            n,
            vector<vector<int>>(m)
        );

        dist[0][0] = grid[0][0];

        // Starting path contains grid[0][0]
        path[0][0].push_back(grid[0][0]);

        minHeap.push({
            grid[0][0],
            {0, 0}
        });

        vector<vector<int>> dir = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        while (!minHeap.empty()) {

            auto cur = minHeap.top();
            minHeap.pop();

            int time = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;

            // Ignore old entry
            if (time > dist[r][c]) {
                continue;
            }

            // Destination reached
            if (r == n - 1 && c == m - 1) {

                int ans = 0;

                // Find maximum elevation in the path
                for (int value : path[r][c]) {
                    ans = max(ans, value);
                }

                return ans;
            }

            // Explore all 4 directions
            for (auto& d : dir) {

                int nr = r + d[0];
                int nc = c + d[1];

                // Boundary check
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m) {
                    continue;
                }

                // Time needed if we move here
                int newTime = max(
                    time,
                    grid[nr][nc]
                );

                // Found a better path
                if (newTime < dist[nr][nc]) {

                    dist[nr][nc] = newTime;

                    // Copy current path
                    path[nr][nc] = path[r][c];

                    // Add the new cell's elevation
                    path[nr][nc].push_back(
                        grid[nr][nc]
                    );

                    minHeap.push({
                        newTime,
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};