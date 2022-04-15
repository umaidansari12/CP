/*
Because we are trying to find the shortest path, use BFS here to exit
immediately when a path reaches the bottom right most cell. Use a set to keep
track of already visited paths. We only need to keep track of the row,
column, and the eliminate obstacle usage count. We don't need to keep track
of the steps because remember we are using BFS for the shortest path. That
means there is no value storing a 4th piece of the data, the current steps.
This will reduce the amount of repeat work. Some analysis of the problem
after trying to solve it for 1 hour

All the cells would be visited more than once as we could reach same cell with
more distance but less obstacles which could be helpful later in traversal so
we need to consider all the paths passing through same cell even with more
distance. Using PQ doesn't make sense here due to reason no 1. so we are
better off with simple queue without any comparator. Here we can also use 2D
array for visited[m][n] = obstacles_till_here, then you will have to check if
you find some cell with lesser no of obstacles reaching this point then
consider that path. 3D array makes life easier in contest, but in interview
its better to discuss about space constraints
*/

class node {
public:
    int x, y, dist, eliminate;
    node(int x, int y, int dist, int eliminate) {
        this->x = x;
        this->y = y;
        this->dist = dist;
        this->eliminate = eliminate;
    }
};

class Solution {
public:
    bool isSafe(int x, int y, int n, int m) {
        return x >= 0 and x<n and y >= 0 and y < m;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 and m == 1)
            return 0;
        if (k > (n + m - 2))
            return n + m - 2;
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        queue<node> q;
        q.push(node(0, 0, 0, k));
        visited[0][0] = 0;
        while (!q.empty()) {
            node curr = q.front();
            q.pop();
            if (curr.x == n - 1 and curr.y == m - 1)
            {
                ans = min(ans, curr.dist);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if (isSafe(nx, ny, n, m) and visited[nx][ny] > k - curr.eliminate)
                {
                    visited[nx][ny] = k - curr.eliminate;
                    if (grid[nx][ny] == 1 and curr.eliminate > 0)
                        q.push(node(nx, ny, curr.dist + 1, curr.eliminate - 1));
                    else if (grid[nx][ny] == 0) {
                        q.push(node(nx, ny, curr.dist + 1, curr.eliminate));
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// C++ Code O(mnk) and space optimized

// USING 3D VISITED ARRAY
// Space Complexity - O(mnk)
// Time Complexity - O(mnk)

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // {r, c, k_left, steps_count}
        queue<vector<int>> pending;
        pending.push({0, 0, k, 0});

        // all 4 directions
        int dirs[4][4] = {
            {0, 1}, {0, -1}, {1, 0}, { -1, 0}
        };

        // visited array for (r,c,k)
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        visited[0][0][k] = 1;

        while (pending.size()) {
            auto curr = pending.front();
            pending.pop();
            int r = curr[0], c = curr[1], k_left = curr[2], steps = curr[3];

            if (r == n - 1 && c == m - 1) {
                return steps;   // we have reached the end with shortest path
            }

            for (auto &dir : dirs) {
                int R = r + dir[0], C = c + dir[1];
                if (R >= 0 && C >= 0 && R < n && C < m && !visited[R][C][k_left]) {
                    // add them to queue if not visited
                    visited[R][C][k_left] = 1;

                    if (grid[R][C] == 1 && k_left > 0)
                        pending.push({R, C, k_left - 1, steps + 1});

                    else if (grid[R][C] == 0)
                        pending.push({R, C, k_left, steps + 1});
                }
            }
        }

        // we never reached (n-1, m-1) point
        return -1;
    }
};

// (SPACE OPTIMIZATION)

// Space Complexity - O(mn) Time Complexity - O(mnk)

// Instead of using a 3D array we can use 2D array with it's coordinates
// denoting cell (r,c) and value denoting number of obstacles we have
// encountered so far if no. of obstacles encountered is less than previous
// value in visited, then we can again add it in the queue

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

// {r, c, k left, steps taken}
        queue<vector<int>> pending;
        pending.push({0, 0, k, 0});
        int ans = INT_MAX;

        int dirs[4][4] = {
            {0, 1}, {0, -1}, {1, 0}, { -1, 0}
        };

        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        visited[0][0] = 0;

        while (pending.size()) {
            auto curr = pending.front();
            pending.pop();

            int r = curr[0], c = curr[1], k_left = curr[2], steps = curr[3];

            if (r == n - 1 && c == m - 1) {
                ans = min(ans, steps);
                break;
            }

            for (auto &dir : dirs) {
                int R = r + dir[0], C = c + dir[1];

// if obstacles occurred till now < prev value of obstacles of (R,C) poisition
                if (R >= 0 && C >= 0 && R < n && C < m && visited[R][C] > k - k_left) {
                    visited[R][C] = k - k_left;
                    if (grid[R][C] == 1 && k_left > 0)
                        pending.push({R, C, k_left - 1, steps + 1});
                    else if (grid[R][C] == 0)
                        pending.push({R, C, k_left, steps + 1});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};